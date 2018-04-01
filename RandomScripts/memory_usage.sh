#!/bin/bash
# To run script infinite times, do:
# watch -n0 bash memory_usage.sh

# Log saved to filename:
filename=syslog.txt

# Log after every 'sleeptime' seconds
sleeptime=1

# Store Date:
date &>> $filename
#date &>> $filename

# Store RAM Usage:
echo RAM Usage: >> $filename
free -m &>> $filename

# CPU Usage:
(printf "CPU Usage: " & mpstat | awk '$3 ~ /CPU/ { for(i=1;i<=NF;i++) { if ($i ~ /%idle/) field=i } } $3 ~ /all/ { print 100 - $field }' ) >> $filename
echo &>> $filename

# GPU USAGE:
(printf "GPU Usage: " & nvidia-smi | grep Default) &>> $filename

# Compiz_worker

(echo & echo "USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND"  & ps aux | grep compiz_worker) &>> $filename

# Python:
ps aux | grep python &>> $filename

echo ---------------------------------------------------------------------------&>> $filename
echo &>> $filename


sleep $sleeptime


