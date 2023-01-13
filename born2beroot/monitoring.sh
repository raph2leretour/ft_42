#!/bin/bash
Architecture=$(uname -a)
CPU=$(lscpu | grep "Socket" | grep -Eo '[0-9]{1,4}')
vCPU=$(lscpu | grep "Core(s)" | grep -Eo '[0-9]{1,4}')
Memory_use=$(free -m | awk '$1 == 'Mem:' {print $3}')
Memory_tot=$(free -m | awk '$1 == 'Mem:' {print $2}')
Memory_perc=$(free | awk '$1 == 'Mem:' {printf("%.2f"), $3/$2*100}')
Disk_use=$(df -Bg | grep '^/dev/' | grep -v '/boot$/' | awk '{ut += $3} END {print ut}')
Disk_tot=$(df -Bg | grep '^/dev/' | grep -v '/boot$/' | awk '{ft += $2} END {print ft}')
Disk_perc=$(df -Bm | grep '^/dev/' | grep -v '/boot$/' | awk '{ut += $3} {ft += $2} END {printf("$d"), ut/ft*100}')
CPU_load=$(echo $[100-$(vmstat 1 2 | tail -1 | awk '{print $15}')]"%")
Last_boot=$(who -b | awk '{print $3 " " $4}')
LVM_use=$(if [ $(lsblk | grep "lvm " | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
Connection_TCP=$(ss -neopt state established | wc -l)
User_log=$(who | wc -l)
Network=$(hostname -I)
Mac=$(ip add | grep link/ether | awk '{print $2}')
Sudo=$(journalctl -q _COMM=sudo | grep COMMAND | wc -l)
wall "	#Architecture: $Architecture
	#CPU physical : $CPU
	#vCPU : $vCPU
	#Memory Usage: $Memory_use/${Memory_tot}MB ($Memory_perc%)
	#Disk Usage: $Disk_use/${Disk_tot}GB ($Disk_perc%)
	#CPU load: $CPU_load
	#Last boot: $Last_boot
	#LVM use: $LVM_use
	#Connections TCP : $Connection_TCP ESTABLISHED
	#User log: $User_log
	#Network: IP $Network ($MAC)
	#Sudo : $Sudo cmd"
