#!/bin/bash

# Usage: e2e-tests.sh image-name

IMAGE=$1
if [ -z "$IMAGE" ]; then
    echo "Image to test required"
    echo "Usage: $0 image-name"
    exit 1
fi


function test_run() {
    args="$1"
    output=$(docker run --rm "$IMAGE" $args)
    echo "$output"
}

test_case='12 x 12'
expected='144.000000'

result=$(test_run "$test_case")

if [ "$result" != "$expected" ]; then
    echo "Failed for ${test_case}: got ${result}, but expected ${expected}"
    exit 1;
fi

echo 'Tests finished successfully'

