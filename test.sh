#!/bin/bash

test_sort() {
    local size=$1
    local limit=$2
    
    echo "Testing size $size..."
    ARG=$(python3 -c "
import random
nums = random.sample(range(-50000, 50000), $size)
print(' '.join(map(str, nums)))
")
    
    ops=$(./push_swap $ARG | wc -l)
    result=$(./push_swap $ARG | ./checker_linux $ARG)
    
    echo "Result: $result"
    echo "Operations: $ops (limit: $limit)"
    
    if [ "$result" = "OK" ]; then
        if [ $ops -le $limit ]; then
            echo "✅ PASS"
        else
            echo "⚠️ WARN - Over by $((ops - limit))"
        fi
    else
        echo "❌ FAIL"
    fi
    echo "-------------------"
}

for size in 100 500; do
    limit=$([[ $size -eq 100 ]] && echo 700 || echo 5500)
    echo "=== Testing $size ==="
    for i in {1..3}; do
        test_sort $size $limit
    done
done
