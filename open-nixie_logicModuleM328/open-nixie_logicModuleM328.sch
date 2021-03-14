EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Timer_RTC:DS3231M U2
U 1 1 5E39B734
P 3250 3250
F 0 "U2" H 3250 2761 50  0000 C CNN
F 1 "DS3231M" H 3250 2670 50  0000 C CNN
F 2 "open-nixie_logicModuleM328:SOIC-16W_7.5x10.3mm_P1.27mm" H 3250 2650 50  0001 C CNN
F 3 "http://datasheets.maximintegrated.com/en/ds/DS3231.pdf" H 3520 3300 50  0001 C CNN
	1    3250 3250
	-1   0    0    1   
$EndComp
$Comp
L MCU_Microchip_ATmega:ATmega328P-AU U1
U 1 1 5E39FFB3
P 6450 3700
F 0 "U1" H 6450 2019 50  0000 C CNN
F 1 "ATmega328P-AU" H 6450 2110 50  0000 C CNN
F 2 "open-nixie_logicModuleM328:TQFP-32_7x7mm_P0.8mm" H 6450 3700 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 6450 3700 50  0001 C CNN
	1    6450 3700
	-1   0    0    1   
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 5E3A4001
P 2500 3950
F 0 "BT1" H 2618 4046 50  0000 L CNN
F 1 "Battery_Cell" H 2618 3955 50  0000 L CNN
F 2 "Battery:cr1225_battery" V 2500 4010 50  0001 C CNN
F 3 "~" V 2500 4010 50  0001 C CNN
	1    2500 3950
	0    1    1    0   
$EndComp
Wire Wire Line
	3750 3350 4100 3350
Wire Wire Line
	4650 3350 4650 3600
Wire Wire Line
	3850 3500 3850 3450
Wire Wire Line
	3850 3450 3750 3450
Wire Wire Line
	3850 3500 3950 3500
$Comp
L MCU_Module:WeMos_D1_mini C1
U 1 1 5E3A8859
P 3700 5350
F 0 "C1" H 3700 4461 50  0000 C CNN
F 1 "WeMos_D1_mini" H 3700 4370 50  0000 C CNN
F 2 "open-nixie_logicModuleM328:WEMOS_D1_mini_light" H 3700 4200 50  0001 C CNN
F 3 "https://wiki.wemos.cc/products:d1:d1_mini#documentation" H 1850 4200 50  0001 C CNN
	1    3700 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 3650 3350 3850
Wire Wire Line
	3350 3850 3650 3850
Wire Wire Line
	3650 3850 3650 3800
Wire Wire Line
	6450 5200 6450 5400
Wire Wire Line
	6450 5400 6650 5400
Wire Wire Line
	6650 5400 6650 5350
$Comp
L power:GND #PWR0104
U 1 1 5E3B788D
P 2200 4050
F 0 "#PWR0104" H 2200 3800 50  0001 C CNN
F 1 "GND" H 2205 3877 50  0000 C CNN
F 2 "" H 2200 4050 50  0001 C CNN
F 3 "" H 2200 4050 50  0001 C CNN
	1    2200 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5E3B8F4E
P 7000 2100
F 0 "#PWR0105" H 7000 1850 50  0001 C CNN
F 1 "GND" H 7005 1927 50  0000 C CNN
F 2 "" H 7000 2100 50  0001 C CNN
F 3 "" H 7000 2100 50  0001 C CNN
	1    7000 2100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5E3BA1B7
P 3700 6400
F 0 "#PWR0106" H 3700 6150 50  0001 C CNN
F 1 "GND" H 3705 6227 50  0000 C CNN
F 2 "" H 3700 6400 50  0001 C CNN
F 3 "" H 3700 6400 50  0001 C CNN
	1    3700 6400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5E3BADA4
P 2850 2750
F 0 "#PWR0107" H 2850 2500 50  0001 C CNN
F 1 "GND" H 2855 2577 50  0000 C CNN
F 2 "" H 2850 2750 50  0001 C CNN
F 3 "" H 2850 2750 50  0001 C CNN
	1    2850 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 2850 3000 2850
Wire Wire Line
	3000 2850 3000 2750
Wire Wire Line
	3000 2750 2850 2750
Wire Wire Line
	6450 2200 6800 2200
Wire Wire Line
	6800 2200 6800 2100
Wire Wire Line
	6800 2100 7000 2100
Wire Wire Line
	3700 6400 3700 6150
Wire Wire Line
	3300 4950 3300 4100
Wire Wire Line
	4650 4100 4650 4200
Wire Wire Line
	4200 4950 4100 4950
Wire Wire Line
	4200 4950 4200 2700
Wire Wire Line
	4100 5450 4850 5450
Wire Wire Line
	4850 5450 4850 4900
Wire Wire Line
	4100 5550 4750 5550
Wire Wire Line
	4750 5550 4750 4800
Wire Wire Line
	4100 5650 4650 5650
Wire Wire Line
	4650 5650 4650 4700
Wire Wire Line
	4550 4600 4550 5750
Wire Wire Line
	4550 5750 4100 5750
$Comp
L Device:R R1
U 1 1 5E3C813A
P 3950 3150
F 0 "R1" H 4020 3196 50  0000 L CNN
F 1 "R" H 4020 3105 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3880 3150 50  0001 C CNN
F 3 "~" H 3950 3150 50  0001 C CNN
	1    3950 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5E3C8D0C
P 4100 3150
F 0 "R2" H 4170 3196 50  0000 L CNN
F 1 "R" H 4170 3105 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4030 3150 50  0001 C CNN
F 3 "~" H 4100 3150 50  0001 C CNN
	1    4100 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 3300 3950 3500
Connection ~ 3950 3500
Wire Wire Line
	4100 3300 4100 3350
Connection ~ 4100 3350
Wire Wire Line
	4100 3000 4000 3000
Wire Wire Line
	4000 3000 4000 2900
Connection ~ 4000 3000
Wire Wire Line
	4000 3000 3950 3000
Wire Wire Line
	4100 5050 4300 5050
Wire Wire Line
	4450 5150 4100 5150
$Comp
L Jumper:Jumper_3_Open JP1
U 1 1 5E3D1F43
P 3700 4300
F 0 "JP1" H 3700 4431 50  0000 C CNN
F 1 "Jumper_3_Open" H 3700 4522 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_Pad1.0x1.5mm" H 3700 4300 50  0001 C CNN
F 3 "~" H 3700 4300 50  0001 C CNN
	1    3700 4300
	-1   0    0    1   
$EndComp
Wire Wire Line
	3300 4100 4650 4100
Wire Wire Line
	3600 4550 3600 4450
Wire Wire Line
	3600 4450 3450 4450
Wire Wire Line
	3450 4450 3450 4300
Wire Wire Line
	3800 4450 3950 4450
Wire Wire Line
	3950 4450 3950 4300
Wire Wire Line
	3800 4450 3800 4550
$Comp
L power:VCC #PWR0101
U 1 1 5E3DB0AC
P 3650 3800
F 0 "#PWR0101" H 3650 3650 50  0001 C CNN
F 1 "VCC" H 3667 3973 50  0000 C CNN
F 2 "" H 3650 3800 50  0001 C CNN
F 3 "" H 3650 3800 50  0001 C CNN
	1    3650 3800
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0102
U 1 1 5E3DB722
P 6650 5350
F 0 "#PWR0102" H 6650 5200 50  0001 C CNN
F 1 "VCC" H 6667 5523 50  0000 C CNN
F 2 "" H 6650 5350 50  0001 C CNN
F 3 "" H 6650 5350 50  0001 C CNN
	1    6650 5350
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0103
U 1 1 5E3DB8D3
P 3700 4050
F 0 "#PWR0103" H 3700 3900 50  0001 C CNN
F 1 "VCC" H 3717 4223 50  0000 C CNN
F 2 "" H 3700 4050 50  0001 C CNN
F 3 "" H 3700 4050 50  0001 C CNN
	1    3700 4050
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0108
U 1 1 5E3DB993
P 4000 2900
F 0 "#PWR0108" H 4000 2750 50  0001 C CNN
F 1 "VCC" H 4017 3073 50  0000 C CNN
F 2 "" H 4000 2900 50  0001 C CNN
F 3 "" H 4000 2900 50  0001 C CNN
	1    4000 2900
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0109
U 1 1 5E3DB9EA
P 5050 3050
F 0 "#PWR0109" H 5050 2900 50  0001 C CNN
F 1 "VCC" H 5067 3223 50  0000 C CNN
F 2 "" H 5050 3050 50  0001 C CNN
F 3 "" H 5050 3050 50  0001 C CNN
	1    5050 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 4150 3700 4050
$Comp
L Connector:TestPoint TP1
U 1 1 5E3DFE7A
P 5200 4400
F 0 "TP1" H 5258 4518 50  0000 L CNN
F 1 "TestPoint" H 5258 4427 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_2.5x2.5mm" H 5400 4400 50  0001 C CNN
F 3 "~" H 5400 4400 50  0001 C CNN
	1    5200 4400
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP3
U 1 1 5E3E0A8F
P 5400 4400
F 0 "TP3" H 5458 4518 50  0000 L CNN
F 1 "TestPoint" H 5458 4427 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_2.5x2.5mm" H 5600 4400 50  0001 C CNN
F 3 "~" H 5600 4400 50  0001 C CNN
	1    5400 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 2700 5850 2700
Wire Wire Line
	4650 3600 5850 3600
Wire Wire Line
	4650 4200 5850 4200
Wire Wire Line
	5400 4400 5850 4400
Wire Wire Line
	5200 4500 5200 4400
Wire Wire Line
	5200 4500 5850 4500
Wire Wire Line
	4550 4600 5850 4600
Wire Wire Line
	4650 4700 5850 4700
Wire Wire Line
	4750 4800 5850 4800
Wire Wire Line
	4850 4900 5850 4900
$Comp
L Connector:TestPoint TP2
U 1 1 5E403333
P 5300 3400
F 0 "TP2" H 5358 3518 50  0000 L CNN
F 1 "TestPoint" H 5358 3427 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_2.5x2.5mm" H 5500 3400 50  0001 C CNN
F 3 "~" H 5500 3400 50  0001 C CNN
	1    5300 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 3400 5300 3400
$Comp
L Device:R R3
U 1 1 5E4055BF
P 5050 3250
F 0 "R3" H 5120 3296 50  0000 L CNN
F 1 "R" H 5120 3205 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4980 3250 50  0001 C CNN
F 3 "~" H 5050 3250 50  0001 C CNN
	1    5050 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 3400 5050 3400
Connection ~ 5300 3400
Wire Wire Line
	5050 3100 5050 3050
$Comp
L Device:Jumper_NO_Small JP2
U 1 1 5E40ADBD
P 4300 3750
F 0 "JP2" V 4254 3798 50  0000 L CNN
F 1 "Jumper_NO_Small" V 4345 3798 50  0000 L CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 4300 3750 50  0001 C CNN
F 3 "~" H 4300 3750 50  0001 C CNN
	1    4300 3750
	0    1    1    0   
$EndComp
$Comp
L Device:Jumper_NO_Small JP3
U 1 1 5E40BACE
P 4450 3750
F 0 "JP3" V 4404 3798 50  0000 L CNN
F 1 "Jumper_NO_Small" V 4495 3798 50  0000 L CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 4450 3750 50  0001 C CNN
F 3 "~" H 4450 3750 50  0001 C CNN
	1    4450 3750
	0    1    1    0   
$EndComp
Wire Wire Line
	3950 3500 4300 3500
Wire Wire Line
	4100 3350 4450 3350
Wire Wire Line
	4300 3650 4300 3500
Connection ~ 4300 3500
Wire Wire Line
	4300 3500 5850 3500
Wire Wire Line
	4450 3650 4450 3350
Connection ~ 4450 3350
Wire Wire Line
	4450 3350 4650 3350
Wire Wire Line
	4300 3850 4300 3950
Wire Wire Line
	4450 3850 4450 5150
Wire Wire Line
	3300 5350 3150 5350
Wire Wire Line
	3150 5350 3150 6750
Wire Wire Line
	3150 6750 5750 6750
Wire Wire Line
	5750 6750 5750 2900
Wire Wire Line
	5750 2900 5850 2900
Wire Wire Line
	5850 3000 5650 3000
Wire Wire Line
	5650 3000 5650 6650
Wire Wire Line
	5650 6650 3050 6650
Wire Wire Line
	3050 6650 3050 5250
Wire Wire Line
	3050 5250 3300 5250
Wire Wire Line
	4300 3950 5550 3950
Wire Wire Line
	5550 3950 5550 3100
Wire Wire Line
	5550 3100 5850 3100
Connection ~ 4300 3950
Wire Wire Line
	4300 3950 4300 5050
Wire Wire Line
	5850 3200 5450 3200
Wire Wire Line
	5450 3200 5450 3850
Wire Wire Line
	5450 3850 4450 3850
Connection ~ 4450 3850
Wire Wire Line
	4100 5250 4950 5250
Wire Wire Line
	4950 5250 4950 3700
Wire Wire Line
	4950 3700 5850 3700
Wire Wire Line
	5850 3800 5050 3800
Wire Wire Line
	5050 3800 5050 5350
Wire Wire Line
	5050 5350 4100 5350
$Comp
L Device:Battery_Cell BT2
U 1 1 5E6ADD0F
P 2500 3700
F 0 "BT2" V 2245 3750 50  0000 C CNN
F 1 "Battery_Cell" V 2336 3750 50  0000 C CNN
F 2 "Battery:cr1225_battery" V 2500 3760 50  0001 C CNN
F 3 "~" V 2500 3760 50  0001 C CNN
	1    2500 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	2700 3950 2700 3800
Wire Wire Line
	2700 3800 3250 3800
Wire Wire Line
	3250 3800 3250 3650
Connection ~ 2700 3800
Wire Wire Line
	2700 3800 2700 3700
Wire Wire Line
	2400 3700 2400 3800
Wire Wire Line
	2400 3800 2200 3800
Wire Wire Line
	2200 3800 2200 4050
Connection ~ 2400 3800
Wire Wire Line
	2400 3800 2400 3950
$Comp
L Device:C C2
U 1 1 5E6C33D8
P 3600 2250
F 0 "C2" H 3485 2204 50  0000 R CNN
F 1 "C" H 3485 2295 50  0000 R CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3638 2100 50  0001 C CNN
F 3 "~" H 3600 2250 50  0001 C CNN
	1    3600 2250
	-1   0    0    1   
$EndComp
$Comp
L Device:C C3
U 1 1 5E6C7F95
P 3950 2250
F 0 "C3" H 3835 2204 50  0000 R CNN
F 1 "C" H 3835 2295 50  0000 R CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3988 2100 50  0001 C CNN
F 3 "~" H 3950 2250 50  0001 C CNN
	1    3950 2250
	-1   0    0    1   
$EndComp
Wire Wire Line
	3600 2400 3800 2400
Wire Wire Line
	3950 2100 3800 2100
$Comp
L power:VCC #PWR0110
U 1 1 5E6CE033
P 3800 2100
F 0 "#PWR0110" H 3800 1950 50  0001 C CNN
F 1 "VCC" H 3817 2273 50  0000 C CNN
F 2 "" H 3800 2100 50  0001 C CNN
F 3 "" H 3800 2100 50  0001 C CNN
	1    3800 2100
	1    0    0    -1  
$EndComp
Connection ~ 3800 2100
Wire Wire Line
	3800 2100 3600 2100
$Comp
L power:GND #PWR0111
U 1 1 5E6CEC64
P 3800 2400
F 0 "#PWR0111" H 3800 2150 50  0001 C CNN
F 1 "GND" H 3805 2227 50  0000 C CNN
F 2 "" H 3800 2400 50  0001 C CNN
F 3 "" H 3800 2400 50  0001 C CNN
	1    3800 2400
	1    0    0    -1  
$EndComp
Connection ~ 3800 2400
Wire Wire Line
	3800 2400 3950 2400
$Comp
L Connector:TestPoint TP4
U 1 1 5E834677
P 7000 2000
F 0 "TP4" H 7058 2118 50  0000 L CNN
F 1 "TestPoint" H 7058 2027 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_2.5x2.5mm" H 7200 2000 50  0001 C CNN
F 3 "~" H 7200 2000 50  0001 C CNN
	1    7000 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 2000 7000 2100
Connection ~ 7000 2100
$EndSCHEMATC
