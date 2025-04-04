#!/bin/bash

# Generate a random battery percentage between 0 and 100
battery_percentage=$((RANDOM % 101))

# Log the battery status
echo "Battery Status: ${battery_percentage}%"

# Check if the battery is below 20%
if [ "$battery_percentage" -lt 20 ]; then
    echo "Battery low! Return to base!"
    exit 1
fi

# Check network connectivity by pinging google.com
ping -c 3 google.com > /dev/null 2>&1

# Check the result of the ping command
if [ $? -ne 0 ]; then
    echo "Communication failure!"
    exit 1
fi

# If both checks pass
echo "All systems operational!"
exit 0
