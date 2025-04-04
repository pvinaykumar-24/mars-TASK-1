#!/bin?bash

#1.create a new directory called rover_mission1 and navigate into it.
 mkdir rover_misssion1
 cd rover_mission1

#2. Create three empty files named log1.txt, log2.txt, and log3.txt inside
# rover_mission1.

touch log1.txt log2.txt log3.txt

#3.Rename log1.txt to mission_log.txt.

mv log1.txt mission_log.txt

#4.Find all files in the current directory that have a .log extension.

echo "Find all files with .log extension:"
find .type f -name "*.log"

#5.Display the contents of mission_log.txt without opening it in an editor.

echo "Content of mission_log.txt"

cat  mission_log.txt

#6.Find and display all lines containing the word "ERROR" in mission_log.txt.

grep "ERROR" mission_log.txt

#7.Count the number of lines in mission_log.txt.++

echo "Number of lines are :"

wc -1 < mission.log.txt

#8.Show the system's current date and time.
echo "date and time"
date

#9.Display the CPU usage of your system in real time.

echo "CPU working in current time:"

top -b -n 1

#10.Schedule a command to shut down the system in 10 minutes.

echo "shuting down in  10 min."

sudo shutdown 10
