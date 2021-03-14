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
L Regulator_Switching:MC34063AD U1
U 1 1 5DB3641D
P 8500 3150
F 0 "U1" H 8500 3617 50  0000 C CNN
F 1 "MC34063AD" H 8500 3526 50  0000 C CNN
F 2 "open-nixie_baseModule:DIP-8_W7.62mm_LongPads" H 8550 2700 50  0001 L CNN
F 3 "http://www.onsemi.com/pub_link/Collateral/MC34063A-D.PDF" H 9000 3050 50  0001 C CNN
	1    8500 3150
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR016
U 1 1 5DB3775C
P 7850 2000
F 0 "#PWR016" H 7850 1850 50  0001 C CNN
F 1 "+12V" H 7865 2173 50  0000 C CNN
F 2 "" H 7850 2000 50  0001 C CNN
F 3 "" H 7850 2000 50  0001 C CNN
	1    7850 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 2950 8050 2950
$Comp
L Device:R R1
U 1 1 5DB38325
P 8500 2000
F 0 "R1" V 8293 2000 50  0000 C CNN
F 1 "1" V 8384 2000 50  0000 C CNN
F 2 "open-nixie_baseModule:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 8430 2000 50  0001 C CNN
F 3 "~" H 8500 2000 50  0001 C CNN
	1    8500 2000
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5DB38906
P 8500 2150
F 0 "R2" V 8293 2150 50  0000 C CNN
F 1 "1" V 8384 2150 50  0000 C CNN
F 2 "open-nixie_baseModule:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 8430 2150 50  0001 C CNN
F 3 "~" H 8500 2150 50  0001 C CNN
	1    8500 2150
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5DB38B11
P 8500 2300
F 0 "R3" V 8293 2300 50  0000 C CNN
F 1 "1" V 8384 2300 50  0000 C CNN
F 2 "open-nixie_baseModule:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 8430 2300 50  0001 C CNN
F 3 "~" H 8500 2300 50  0001 C CNN
	1    8500 2300
	0    1    1    0   
$EndComp
Wire Wire Line
	8900 2950 8900 2300
Wire Wire Line
	8900 2300 8650 2300
Wire Wire Line
	8900 2300 8900 2150
Wire Wire Line
	8900 2150 8650 2150
Connection ~ 8900 2300
Wire Wire Line
	8900 2150 8900 2000
Wire Wire Line
	8900 2000 8650 2000
Connection ~ 8900 2150
Wire Wire Line
	8350 2000 8050 2000
Wire Wire Line
	8050 2000 8050 2150
Wire Wire Line
	8350 2150 8050 2150
Connection ~ 8050 2150
Wire Wire Line
	8050 2150 8050 2300
Wire Wire Line
	8350 2300 8050 2300
Connection ~ 8050 2300
Wire Wire Line
	8050 2300 8050 2950
$Comp
L Device:R R4
U 1 1 5DB396B6
P 9150 2800
F 0 "R4" H 9220 2846 50  0000 L CNN
F 1 "100" H 9220 2755 50  0000 L CNN
F 2 "open-nixie_baseModule:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 9080 2800 50  0001 C CNN
F 3 "~" H 9150 2800 50  0001 C CNN
	1    9150 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 3050 9150 3050
Wire Wire Line
	8900 3150 9350 3150
Wire Wire Line
	9350 3150 9350 2300
$Comp
L Device:L L1
U 1 1 5DB3A4B1
P 9500 2300
F 0 "L1" V 9690 2300 50  0000 C CNN
F 1 "220u" V 9599 2300 50  0000 C CNN
F 2 "open-nixie_baseModule:Inductor_3_5" H 9500 2300 50  0001 C CNN
F 3 "~" H 9500 2300 50  0001 C CNN
	1    9500 2300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8900 3350 9000 3350
Wire Wire Line
	9200 3350 9200 3450
$Comp
L power:GND #PWR017
U 1 1 5DB3B563
P 8500 3800
F 0 "#PWR017" H 8500 3550 50  0001 C CNN
F 1 "GND" H 8505 3627 50  0000 C CNN
F 2 "" H 8500 3800 50  0001 C CNN
F 3 "" H 8500 3800 50  0001 C CNN
	1    8500 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 3800 8500 3750
Wire Wire Line
	9250 3800 9000 3800
Wire Wire Line
	9000 3800 9000 3350
Connection ~ 9000 3350
Wire Wire Line
	9000 3350 9200 3350
Wire Wire Line
	9550 3600 9650 3600
$Comp
L Device:R R5
U 1 1 5DB3E5F2
P 9000 3950
F 0 "R5" H 9070 3996 50  0000 L CNN
F 1 "1k" H 9070 3905 50  0000 L CNN
F 2 "open-nixie_baseModule:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 8930 3950 50  0001 C CNN
F 3 "~" H 9000 3950 50  0001 C CNN
	1    9000 3950
	1    0    0    -1  
$EndComp
Connection ~ 9000 3800
Wire Wire Line
	9000 4100 9300 4100
Wire Wire Line
	9550 4100 9550 4000
$Comp
L power:GND #PWR020
U 1 1 5DB3F31A
P 9300 4100
F 0 "#PWR020" H 9300 3850 50  0001 C CNN
F 1 "GND" H 9305 3927 50  0000 C CNN
F 2 "" H 9300 4100 50  0001 C CNN
F 3 "" H 9300 4100 50  0001 C CNN
	1    9300 4100
	1    0    0    -1  
$EndComp
Connection ~ 9300 4100
Wire Wire Line
	9300 4100 9550 4100
$Comp
L Transistor_FET:IRF740 Q1
U 1 1 5DB3FF69
P 9850 3450
F 0 "Q1" H 10056 3496 50  0000 L CNN
F 1 "IRF740" H 10056 3405 50  0000 L CNN
F 2 "open-nixie_baseModule:TO-220-3_Horizontal_TabDown" H 10100 3375 50  0001 L CIN
F 3 "http://www.vishay.com/docs/91054/91054.pdf" H 9850 3450 50  0001 L CNN
	1    9850 3450
	1    0    0    -1  
$EndComp
Connection ~ 9350 2300
Wire Wire Line
	9650 2300 9750 2300
$Comp
L pspice:DIODE D1
U 1 1 5DB499F1
P 10000 2300
F 0 "D1" H 10000 2565 50  0000 C CNN
F 1 "1N4349" H 10000 2474 50  0000 C CNN
F 2 "open-nixie_baseModule:D_DO-41_SOD81_P12.70mm_Horizontal" H 10000 2300 50  0001 C CNN
F 3 "~" H 10000 2300 50  0001 C CNN
	1    10000 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C5
U 1 1 5DB4A530
P 10350 2450
F 0 "C5" H 10468 2496 50  0000 L CNN
F 1 "2u2" H 10468 2405 50  0000 L CNN
F 2 "open-nixie_baseModule:CP_Radial_D8.0mm_P3.80mm" H 10388 2300 50  0001 C CNN
F 3 "~" H 10350 2450 50  0001 C CNN
	1    10350 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	10200 2300 10350 2300
$Comp
L power:GND #PWR021
U 1 1 5DB4B63D
P 10350 2600
F 0 "#PWR021" H 10350 2350 50  0001 C CNN
F 1 "GND" H 10355 2427 50  0000 C CNN
F 2 "" H 10350 2600 50  0001 C CNN
F 3 "" H 10350 2600 50  0001 C CNN
	1    10350 2600
	1    0    0    -1  
$EndComp
Text GLabel 10300 1850 0    50   Input ~ 0
HV
Wire Wire Line
	10350 2300 10350 1850
Wire Wire Line
	10350 1850 10300 1850
Connection ~ 10350 2300
Wire Wire Line
	10350 2300 10750 2300
Wire Wire Line
	10750 2300 10750 2550
$Comp
L Device:R R6
U 1 1 5DB4D911
P 10750 2700
F 0 "R6" H 10820 2746 50  0000 L CNN
F 1 "470k" H 10820 2655 50  0000 L CNN
F 2 "open-nixie_baseModule:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 10680 2700 50  0001 C CNN
F 3 "~" H 10750 2700 50  0001 C CNN
	1    10750 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 5DB4DE06
P 10750 3500
F 0 "R7" H 10820 3546 50  0000 L CNN
F 1 "2k7" H 10820 3455 50  0000 L CNN
F 2 "open-nixie_baseModule:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 10680 3500 50  0001 C CNN
F 3 "~" H 10750 3500 50  0001 C CNN
	1    10750 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV1
U 1 1 5DB4E4B7
P 10750 3100
F 0 "RV1" H 10680 3054 50  0000 R CNN
F 1 "1k" H 10680 3145 50  0000 R CNN
F 2 "open-nixie_baseModule:Potentiometer_Bourns_3266Z_Horizontal" H 10750 3100 50  0001 C CNN
F 3 "~" H 10750 3100 50  0001 C CNN
	1    10750 3100
	-1   0    0    1   
$EndComp
Wire Wire Line
	10750 2950 10750 2850
Wire Wire Line
	10750 3350 10750 3250
Wire Wire Line
	9550 4100 9950 4100
Wire Wire Line
	10750 4100 10750 3650
Connection ~ 9550 4100
Wire Wire Line
	8900 3450 8900 4350
Wire Wire Line
	8900 4350 10500 4350
Wire Wire Line
	10500 4350 10500 3100
Wire Wire Line
	10500 3100 10600 3100
$Comp
L Device:C C3
U 1 1 5DB52B47
P 7950 3500
F 0 "C3" H 8065 3546 50  0000 L CNN
F 1 "1n" H 8065 3455 50  0000 L CNN
F 2 "open-nixie_baseModule:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7988 3350 50  0001 C CNN
F 3 "~" H 7950 3500 50  0001 C CNN
	1    7950 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 3350 7950 3350
Wire Wire Line
	7950 3650 7950 3750
Wire Wire Line
	7950 3750 8500 3750
Connection ~ 8500 3750
Wire Wire Line
	8500 3750 8500 3650
$Comp
L Transistor_BJT:BC557 Q2
U 1 1 5DB553FE
P 9450 3800
F 0 "Q2" H 9641 3846 50  0000 L CNN
F 1 "BC557" H 9641 3755 50  0000 L CNN
F 2 "open-nixie_baseModule:TO-92_Inline_Wide" H 9650 3725 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC557.pdf" H 9450 3800 50  0001 L CNN
	1    9450 3800
	1    0    0    1   
$EndComp
$Comp
L Diode:1N4148 D2
U 1 1 5DB5656A
P 9500 3450
F 0 "D2" H 9500 3234 50  0000 C CNN
F 1 "1N4148" H 9500 3325 50  0000 C CNN
F 2 "open-nixie_baseModule:D_SOD-123" H 9500 3275 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/1N4148_1N4448.pdf" H 9500 3450 50  0001 C CNN
	1    9500 3450
	-1   0    0    1   
$EndComp
Wire Wire Line
	9200 3450 9350 3450
Connection ~ 9650 3450
Wire Wire Line
	9650 3450 9650 3600
Wire Wire Line
	7850 2000 8050 2000
Connection ~ 8050 2000
$Comp
L power:+12V #PWR018
U 1 1 5DB5D85B
P 9550 5000
F 0 "#PWR018" H 9550 4850 50  0001 C CNN
F 1 "+12V" H 9565 5173 50  0000 C CNN
F 2 "" H 9550 5000 50  0001 C CNN
F 3 "" H 9550 5000 50  0001 C CNN
	1    9550 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9550 5100 9550 5000
$Comp
L power:GND #PWR019
U 1 1 5DB5F157
P 9550 5400
F 0 "#PWR019" H 9550 5150 50  0001 C CNN
F 1 "GND" H 9555 5227 50  0000 C CNN
F 2 "" H 9550 5400 50  0001 C CNN
F 3 "" H 9550 5400 50  0001 C CNN
	1    9550 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9550 5400 9550 5300
$Comp
L Connector:Conn_01x02_Male J5
U 1 1 5DB61ECE
P 10000 4650
F 0 "J5" V 10062 4694 50  0000 L CNN
F 1 "Conn_01x02_Male" V 10153 4694 50  0000 L CNN
F 2 "open-nixie_baseModule:PinHeader_1x02_P2.54mm_Vertical" H 10000 4650 50  0001 C CNN
F 3 "~" H 10000 4650 50  0001 C CNN
	1    10000 4650
	0    1    1    0   
$EndComp
Connection ~ 9550 5300
$Comp
L Device:CP C1
U 1 1 5DB66084
P 10150 5150
F 0 "C1" H 10268 5196 50  0000 L CNN
F 1 "330u" H 10268 5105 50  0000 L CNN
F 2 "open-nixie_baseModule:CP_Radial_D8.0mm_P3.80mm" H 10188 5000 50  0001 C CNN
F 3 "~" H 10150 5150 50  0001 C CNN
	1    10150 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:Fuse F1
U 1 1 5DB697B2
P 9300 5100
F 0 "F1" V 9103 5100 50  0000 C CNN
F 1 "Fuse" V 9194 5100 50  0000 C CNN
F 2 "open-nixie_baseModule:D_DO-41_SOD81_P12.70mm_Horizontal" V 9230 5100 50  0001 C CNN
F 3 "~" H 9300 5100 50  0001 C CNN
	1    9300 5100
	0    1    1    0   
$EndComp
Wire Wire Line
	9400 5100 9450 5100
Wire Wire Line
	9550 5300 9900 5300
Wire Wire Line
	9550 5100 9850 5100
Wire Wire Line
	9850 5100 9850 5000
Wire Wire Line
	9850 5000 10000 5000
Connection ~ 9550 5100
Connection ~ 9450 5100
Wire Wire Line
	9450 5100 9550 5100
Wire Wire Line
	9150 5100 9000 5100
$Comp
L MCU_Module:WeMos_D1_mini U2
U 1 1 5DB7A3B0
P 2300 2700
F 0 "U2" H 2300 1811 50  0000 C CNN
F 1 "Logic Module" H 2300 1720 50  0000 C CNN
F 2 "open-nixie_baseModule:wemos-d1-mini-with-pin-header-pin-correct" H 2300 1550 50  0001 C CNN
F 3 "https://wiki.wemos.cc/products:d1:d1_mini#documentation" H 450 1550 50  0001 C CNN
	1    2300 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9950 4100 9950 3650
Connection ~ 9950 4100
Wire Wire Line
	9950 4100 10250 4100
Wire Wire Line
	9950 3250 9950 2650
Wire Wire Line
	9950 2650 9750 2650
Wire Wire Line
	9750 2650 9750 2300
Connection ~ 9750 2300
Wire Wire Line
	9750 2300 9800 2300
Wire Wire Line
	10500 3100 10250 3100
Wire Wire Line
	10250 3100 10250 3650
Connection ~ 10500 3100
$Comp
L Device:C C4
U 1 1 5DB82EB5
P 10250 3800
F 0 "C4" H 10365 3846 50  0000 L CNN
F 1 "100n" H 10365 3755 50  0000 L CNN
F 2 "open-nixie_baseModule:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 10288 3650 50  0001 C CNN
F 3 "~" H 10250 3800 50  0001 C CNN
	1    10250 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	10250 3950 10250 4100
Connection ~ 10250 4100
Wire Wire Line
	10250 4100 10750 4100
$Comp
L Connector:Conn_01x03_Male Module1
U 1 1 5DB85425
P 7450 1200
F 0 "Module1" V 7512 1344 50  0000 L CNN
F 1 "DC Converter Module" V 7603 1344 50  0000 L CNN
F 2 "open-nixie_baseModule:PinHeader_1x03_P2.54mm_Vertical" H 7450 1200 50  0001 C CNN
F 3 "~" H 7450 1200 50  0001 C CNN
	1    7450 1200
	0    1    1    0   
$EndComp
Wire Wire Line
	7450 1400 7450 1550
$Comp
L power:GND #PWR014
U 1 1 5DB8CAD8
P 7450 1650
F 0 "#PWR014" H 7450 1400 50  0001 C CNN
F 1 "GND" H 7455 1477 50  0000 C CNN
F 2 "" H 7450 1650 50  0001 C CNN
F 3 "" H 7450 1650 50  0001 C CNN
	1    7450 1650
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR015
U 1 1 5DB8D605
P 7700 1150
F 0 "#PWR015" H 7700 1000 50  0001 C CNN
F 1 "+12V" H 7715 1323 50  0000 C CNN
F 2 "" H 7700 1150 50  0001 C CNN
F 3 "" H 7700 1150 50  0001 C CNN
	1    7700 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 1400 7700 1400
Wire Wire Line
	7350 1400 7200 1400
$Comp
L power:+5V #PWR013
U 1 1 5DB92E1E
P 7200 1150
F 0 "#PWR013" H 7200 1000 50  0001 C CNN
F 1 "+5V" H 7215 1323 50  0000 C CNN
F 2 "" H 7200 1150 50  0001 C CNN
F 3 "" H 7200 1150 50  0001 C CNN
	1    7200 1150
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR04
U 1 1 5DB9DDE7
P 2200 1800
F 0 "#PWR04" H 2200 1650 50  0001 C CNN
F 1 "+5V" H 2215 1973 50  0000 C CNN
F 2 "" H 2200 1800 50  0001 C CNN
F 3 "" H 2200 1800 50  0001 C CNN
	1    2200 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 1900 2400 1850
Wire Wire Line
	2200 1900 2200 1800
$Comp
L power:GND #PWR05
U 1 1 5DBA3277
P 2300 3600
F 0 "#PWR05" H 2300 3350 50  0001 C CNN
F 1 "GND" H 2305 3427 50  0000 C CNN
F 2 "" H 2300 3600 50  0001 C CNN
F 3 "" H 2300 3600 50  0001 C CNN
	1    2300 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 3600 2300 3500
$Comp
L Connector:Conn_01x05_Female J1
U 1 1 5DB362CE
P 3800 2600
F 0 "J1" H 3828 2626 50  0000 L CNN
F 1 "Conn_01x05_Female" H 3828 2535 50  0000 L CNN
F 2 "open-nixie_baseModule:PinHeader_1x05_P2.54mm_Vertical" H 3800 2600 50  0001 C CNN
F 3 "~" H 3800 2600 50  0001 C CNN
	1    3800 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 2300 3100 2000
Text GLabel 3100 2000 0    50   Input ~ 0
HV
$Comp
L Connector:Conn_01x06_Female J2
U 1 1 5DB4843B
P 3500 3100
F 0 "J2" H 3528 3076 50  0000 L CNN
F 1 "Conn_01x06_Female" H 3528 2985 50  0000 L CNN
F 2 "open-nixie_baseModule:PinHeader_1x06_P2.54mm_Vertical" H 3500 3100 50  0001 C CNN
F 3 "~" H 3500 3100 50  0001 C CNN
	1    3500 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 3100 3200 3100
Wire Wire Line
	3200 3100 3200 2850
Wire Wire Line
	3300 3200 3200 3200
Wire Wire Line
	3200 3200 3200 3450
$Comp
L power:+5V #PWR07
U 1 1 5DB5C2D1
P 3200 2850
F 0 "#PWR07" H 3200 2700 50  0001 C CNN
F 1 "+5V" H 3215 3023 50  0000 C CNN
F 2 "" H 3200 2850 50  0001 C CNN
F 3 "" H 3200 2850 50  0001 C CNN
	1    3200 2850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5DB5CFF4
P 3200 3550
F 0 "#PWR08" H 3200 3300 50  0001 C CNN
F 1 "GND" H 3205 3377 50  0000 C CNN
F 2 "" H 3200 3550 50  0001 C CNN
F 3 "" H 3200 3550 50  0001 C CNN
	1    3200 3550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5DB689D0
P 1350 3900
F 0 "SW1" H 1350 4185 50  0000 C CNN
F 1 "SW_Push" H 1350 4094 50  0000 C CNN
F 2 "open-nixie_baseModule:SW_TH_Tactile_Omron_B3F-10xx_2pol" H 1350 4100 50  0001 C CNN
F 3 "~" H 1350 4100 50  0001 C CNN
	1    1350 3900
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5DB692D3
P 1350 4300
F 0 "SW2" H 1350 4585 50  0000 C CNN
F 1 "SW_Push" H 1350 4494 50  0000 C CNN
F 2 "open-nixie_baseModule:SW_TH_Tactile_Omron_B3F-10xx_2pol" H 1350 4500 50  0001 C CNN
F 3 "~" H 1350 4500 50  0001 C CNN
	1    1350 4300
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 5DB69935
P 1350 4750
F 0 "SW3" H 1350 5035 50  0000 C CNN
F 1 "SW_Push" H 1350 4944 50  0000 C CNN
F 2 "open-nixie_baseModule:SW_TH_Tactile_Omron_B3F-10xx_2pol" H 1350 4950 50  0001 C CNN
F 3 "~" H 1350 4950 50  0001 C CNN
	1    1350 4750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5DB7041B
P 1550 3900
F 0 "#PWR01" H 1550 3650 50  0001 C CNN
F 1 "GND" H 1555 3727 50  0000 C CNN
F 2 "" H 1550 3900 50  0001 C CNN
F 3 "" H 1550 3900 50  0001 C CNN
	1    1550 3900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5DB70DD0
P 1550 4300
F 0 "#PWR02" H 1550 4050 50  0001 C CNN
F 1 "GND" H 1555 4127 50  0000 C CNN
F 2 "" H 1550 4300 50  0001 C CNN
F 3 "" H 1550 4300 50  0001 C CNN
	1    1550 4300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5DB71697
P 1550 4750
F 0 "#PWR03" H 1550 4500 50  0001 C CNN
F 1 "GND" H 1555 4577 50  0000 C CNN
F 2 "" H 1550 4750 50  0001 C CNN
F 3 "" H 1550 4750 50  0001 C CNN
	1    1550 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 3900 1100 3900
Wire Wire Line
	1100 3900 1100 3500
Wire Wire Line
	1100 2700 1700 2700
Wire Wire Line
	1150 4300 1050 4300
Wire Wire Line
	1050 4300 1050 2600
Wire Wire Line
	1050 2600 1400 2600
Wire Wire Line
	1150 4750 1000 4750
Wire Wire Line
	1000 4750 1000 2300
Wire Wire Line
	1000 2300 1100 2300
Wire Wire Line
	2700 2300 2950 2300
Wire Wire Line
	2950 2300 2950 2150
$Comp
L Device:R R8
U 1 1 5DB84C2B
P 3800 2150
F 0 "R8" V 3593 2150 50  0000 C CNN
F 1 "R" V 3684 2150 50  0000 C CNN
F 2 "open-nixie_baseModule:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3730 2150 50  0001 C CNN
F 3 "~" H 3800 2150 50  0001 C CNN
	1    3800 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	2950 2150 3650 2150
Wire Wire Line
	3950 2150 4100 2150
$Comp
L Device:LED D3
U 1 1 5DB8E92E
P 4850 1500
F 0 "D3" H 4843 1716 50  0000 C CNN
F 1 "LED" H 4843 1625 50  0000 C CNN
F 2 "open-nixie_baseModule:LED_PLCC_2835_Handsoldering" H 4850 1500 50  0001 C CNN
F 3 "~" H 4850 1500 50  0001 C CNN
	1    4850 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D5
U 1 1 5DB8EEB9
P 4850 1800
F 0 "D5" H 4843 2016 50  0000 C CNN
F 1 "LED" H 4843 1925 50  0000 C CNN
F 2 "open-nixie_baseModule:LED_PLCC_2835_Handsoldering" H 4850 1800 50  0001 C CNN
F 3 "~" H 4850 1800 50  0001 C CNN
	1    4850 1800
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D4
U 1 1 5DB8F286
P 5550 1500
F 0 "D4" H 5543 1716 50  0000 C CNN
F 1 "LED" H 5543 1625 50  0000 C CNN
F 2 "open-nixie_baseModule:LED_PLCC_2835_Handsoldering" H 5550 1500 50  0001 C CNN
F 3 "~" H 5550 1500 50  0001 C CNN
	1    5550 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D6
U 1 1 5DB8F508
P 5550 1800
F 0 "D6" H 5543 2016 50  0000 C CNN
F 1 "LED" H 5543 1925 50  0000 C CNN
F 2 "open-nixie_baseModule:LED_PLCC_2835_Handsoldering" H 5550 1800 50  0001 C CNN
F 3 "~" H 5550 1800 50  0001 C CNN
	1    5550 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 1500 5400 1500
Wire Wire Line
	5000 1800 5400 1800
Wire Wire Line
	4700 1800 4400 1800
Wire Wire Line
	4400 1800 4400 1950
Wire Wire Line
	4700 1500 4400 1500
Wire Wire Line
	4400 1500 4400 1800
Connection ~ 4400 1800
$Comp
L Device:R R9
U 1 1 5DBA34C7
P 5850 1500
F 0 "R9" V 5643 1500 50  0000 C CNN
F 1 "R" V 5734 1500 50  0000 C CNN
F 2 "open-nixie_baseModule:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5780 1500 50  0001 C CNN
F 3 "~" H 5850 1500 50  0001 C CNN
	1    5850 1500
	0    1    1    0   
$EndComp
$Comp
L Device:R R10
U 1 1 5DBA3963
P 5850 1800
F 0 "R10" V 5643 1800 50  0000 C CNN
F 1 "R" V 5734 1800 50  0000 C CNN
F 2 "open-nixie_baseModule:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5780 1800 50  0001 C CNN
F 3 "~" H 5850 1800 50  0001 C CNN
	1    5850 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	6000 1800 6200 1800
Wire Wire Line
	6200 1800 6200 1500
Wire Wire Line
	6000 1500 6200 1500
Connection ~ 6200 1500
Wire Wire Line
	6200 1500 6200 1300
$Comp
L power:+12V #PWR012
U 1 1 5DBAEABD
P 6200 1150
F 0 "#PWR012" H 6200 1000 50  0001 C CNN
F 1 "+12V" H 6215 1323 50  0000 C CNN
F 2 "" H 6200 1150 50  0001 C CNN
F 3 "" H 6200 1150 50  0001 C CNN
	1    6200 1150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR011
U 1 1 5DBAF695
P 4400 2350
F 0 "#PWR011" H 4400 2100 50  0001 C CNN
F 1 "GND" H 4405 2177 50  0000 C CNN
F 2 "" H 4400 2350 50  0001 C CNN
F 3 "" H 4400 2350 50  0001 C CNN
	1    4400 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R11
U 1 1 5DBB0251
P 1100 1900
F 0 "R11" H 1170 1946 50  0000 L CNN
F 1 "10k" H 1170 1855 50  0000 L CNN
F 2 "open-nixie_baseModule:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 1030 1900 50  0001 C CNN
F 3 "~" H 1100 1900 50  0001 C CNN
	1    1100 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R12
U 1 1 5DBB0899
P 1400 1900
F 0 "R12" H 1470 1946 50  0000 L CNN
F 1 "10k" H 1470 1855 50  0000 L CNN
F 2 "open-nixie_baseModule:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 1330 1900 50  0001 C CNN
F 3 "~" H 1400 1900 50  0001 C CNN
	1    1400 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R13
U 1 1 5DBB0A56
P 1700 1900
F 0 "R13" H 1770 1946 50  0000 L CNN
F 1 "10k" H 1770 1855 50  0000 L CNN
F 2 "open-nixie_baseModule:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 1630 1900 50  0001 C CNN
F 3 "~" H 1700 1900 50  0001 C CNN
	1    1700 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 2300 1100 2050
Connection ~ 1100 2300
Wire Wire Line
	1100 2300 1900 2300
Wire Wire Line
	1400 2050 1400 2600
Connection ~ 1400 2600
Wire Wire Line
	1400 2600 1900 2600
Wire Wire Line
	1700 2050 1700 2700
Connection ~ 1700 2700
Wire Wire Line
	1700 2700 1900 2700
Wire Wire Line
	1100 1750 1400 1750
Wire Wire Line
	1700 1750 1400 1750
Connection ~ 1400 1750
Wire Wire Line
	2400 1850 1850 1850
Wire Wire Line
	1850 1850 1850 1750
Wire Wire Line
	1850 1750 1700 1750
Connection ~ 2400 1850
Wire Wire Line
	2400 1850 2400 1800
Connection ~ 1700 1750
$Comp
L Device:R R14
U 1 1 5DBD6674
P 2850 2800
F 0 "R14" V 2643 2800 50  0000 C CNN
F 1 "100" V 2734 2800 50  0000 C CNN
F 2 "open-nixie_baseModule:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2780 2800 50  0001 C CNN
F 3 "~" H 2850 2800 50  0001 C CNN
	1    2850 2800
	0    1    1    0   
$EndComp
$Comp
L Device:R R15
U 1 1 5DBD6CFF
P 2850 2900
F 0 "R15" V 2643 2900 50  0000 C CNN
F 1 "100" V 2734 2900 50  0000 C CNN
F 2 "open-nixie_baseModule:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2780 2900 50  0001 C CNN
F 3 "~" H 2850 2900 50  0001 C CNN
	1    2850 2900
	0    1    1    0   
$EndComp
$Comp
L Device:R R16
U 1 1 5DBD6EF8
P 2850 3000
F 0 "R16" V 2643 3000 50  0000 C CNN
F 1 "100" V 2734 3000 50  0000 C CNN
F 2 "open-nixie_baseModule:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2780 3000 50  0001 C CNN
F 3 "~" H 2850 3000 50  0001 C CNN
	1    2850 3000
	0    1    1    0   
$EndComp
$Comp
L Device:R R17
U 1 1 5DBD708D
P 2850 3100
F 0 "R17" V 2643 3100 50  0000 C CNN
F 1 "100" V 2734 3100 50  0000 C CNN
F 2 "open-nixie_baseModule:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2780 3100 50  0001 C CNN
F 3 "~" H 2850 3100 50  0001 C CNN
	1    2850 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	3000 2800 3100 2800
Wire Wire Line
	3100 2800 3100 2900
Wire Wire Line
	3100 2900 3300 2900
Wire Wire Line
	3000 2900 3050 2900
Wire Wire Line
	3050 2900 3050 2950
Wire Wire Line
	3050 2950 3300 2950
Wire Wire Line
	3300 2950 3300 3000
Wire Wire Line
	3000 3000 3150 3000
Wire Wire Line
	3150 3000 3150 3300
Wire Wire Line
	3150 3300 3300 3300
Wire Wire Line
	3300 3400 3100 3400
Wire Wire Line
	3100 3400 3100 3100
Wire Wire Line
	3100 3100 3000 3100
$Comp
L Connector:Conn_01x03_Female J3
U 1 1 5DBF0867
P 3900 4100
F 0 "J3" V 3838 3912 50  0000 R CNN
F 1 "IR Sensor" V 3747 3912 50  0000 R CNN
F 2 "open-nixie_baseModule:PinHeader_1x03_P2.54mm_Vertical" H 3900 4100 50  0001 C CNN
F 3 "~" H 3900 4100 50  0001 C CNN
	1    3900 4100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3800 4300 1800 4300
Wire Wire Line
	1800 4300 1800 3500
Wire Wire Line
	1800 3500 1100 3500
Connection ~ 1100 3500
Wire Wire Line
	1100 3500 1100 2700
$Comp
L power:GND #PWR09
U 1 1 5DBF8D0C
P 3900 4400
F 0 "#PWR09" H 3900 4150 50  0001 C CNN
F 1 "GND" H 3905 4227 50  0000 C CNN
F 2 "" H 3900 4400 50  0001 C CNN
F 3 "" H 3900 4400 50  0001 C CNN
	1    3900 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 4400 3900 4300
Wire Wire Line
	4000 4300 4000 4350
Wire Wire Line
	4000 4350 4200 4350
$Comp
L power:+3.3V #PWR010
U 1 1 5DC083D0
P 4200 3900
F 0 "#PWR010" H 4200 3750 50  0001 C CNN
F 1 "+3.3V" H 4215 4073 50  0000 C CNN
F 2 "" H 4200 3900 50  0001 C CNN
F 3 "" H 4200 3900 50  0001 C CNN
	1    4200 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 3900 4200 4350
$Comp
L Device:C C2
U 1 1 5DC15A04
P 10500 5150
F 0 "C2" H 10615 5196 50  0000 L CNN
F 1 "100n" H 10615 5105 50  0000 L CNN
F 2 "open-nixie_baseModule:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 10538 5000 50  0001 C CNN
F 3 "~" H 10500 5150 50  0001 C CNN
	1    10500 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 5000 10500 5000
Connection ~ 10150 5000
Wire Wire Line
	10150 5300 10500 5300
Connection ~ 10150 5300
Wire Wire Line
	3100 2300 3400 2300
Wire Wire Line
	3400 2300 3400 2800
Wire Wire Line
	3400 2800 3600 2800
Wire Wire Line
	2700 2400 3600 2400
Wire Wire Line
	2700 2500 3600 2500
Wire Wire Line
	2700 2600 3600 2600
Wire Wire Line
	2700 2700 3600 2700
$Comp
L Connector:Conn_01x02_Male J6
U 1 1 5DBCB58B
P 6650 2800
F 0 "J6" H 6758 2981 50  0000 C CNN
F 1 "Conn_01x02_Male" H 6758 2890 50  0000 C CNN
F 2 "open-nixie_baseModule:PinHeader_1x02_P2.54mm_Vertical" H 6650 2800 50  0001 C CNN
F 3 "~" H 6650 2800 50  0001 C CNN
	1    6650 2800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5DBCCA12
P 6900 3100
F 0 "#PWR0101" H 6900 2850 50  0001 C CNN
F 1 "GND" H 6905 2927 50  0000 C CNN
F 2 "" H 6900 3100 50  0001 C CNN
F 3 "" H 6900 3100 50  0001 C CNN
	1    6900 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 2900 6900 2900
Wire Wire Line
	6900 2900 6900 3100
Wire Wire Line
	6850 2800 6900 2800
Wire Wire Line
	6900 2800 6900 2500
$Comp
L Device:R R18
U 1 1 5DBDD6D0
P 6900 2350
F 0 "R18" H 6970 2396 50  0000 L CNN
F 1 "R" H 6970 2305 50  0000 L CNN
F 2 "open-nixie_baseModule:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6830 2350 50  0001 C CNN
F 3 "~" H 6900 2350 50  0001 C CNN
	1    6900 2350
	1    0    0    -1  
$EndComp
$Comp
L Jumper:Jumper_3_Open JP1
U 1 1 5DBDEA0D
P 6900 2050
F 0 "JP1" H 6900 2274 50  0000 C CNN
F 1 "Jumper_3_Open" H 6900 2183 50  0000 C CNN
F 2 "open-nixie_baseModule:SolderJumper-3_P1.3mm_Open_RoundedPad1.0x1.5mm_NumberLabels" H 6900 2050 50  0001 C CNN
F 3 "~" H 6900 2050 50  0001 C CNN
	1    6900 2050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 5DBE059B
P 6650 1800
F 0 "#PWR0102" H 6650 1650 50  0001 C CNN
F 1 "+5V" H 6665 1973 50  0000 C CNN
F 2 "" H 6650 1800 50  0001 C CNN
F 3 "" H 6650 1800 50  0001 C CNN
	1    6650 1800
	1    0    0    -1  
$EndComp
Text GLabel 7150 1800 0    50   Input ~ 0
HV
Wire Wire Line
	7150 2050 7150 1800
Wire Wire Line
	6650 2050 6650 1800
$Comp
L power:+3.3V #PWR0103
U 1 1 5DC099F0
P 2400 1800
F 0 "#PWR0103" H 2400 1650 50  0001 C CNN
F 1 "+3.3V" H 2415 1973 50  0000 C CNN
F 2 "" H 2400 1800 50  0001 C CNN
F 3 "" H 2400 1800 50  0001 C CNN
	1    2400 1800
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:KA78M05_TO252 U3
U 1 1 5DBE0EFE
P 6750 1200
F 0 "U3" H 6750 1442 50  0000 C CNN
F 1 "KA78M05_TO252" H 6750 1351 50  0000 C CNN
F 2 "open-nixie_baseModule:TO-252-2" H 6750 1425 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM78M05.pdf" H 6750 1150 50  0001 C CNN
	1    6750 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 1550 7100 1550
Wire Wire Line
	6750 1550 6750 1500
Connection ~ 7450 1550
Wire Wire Line
	7450 1550 7450 1650
Wire Wire Line
	7700 1400 7700 1150
Wire Wire Line
	7200 1400 7200 1250
Wire Wire Line
	7050 1200 7050 1250
Wire Wire Line
	7050 1250 7100 1250
Connection ~ 7200 1250
Wire Wire Line
	7200 1250 7200 1150
Wire Wire Line
	6450 1200 6300 1200
Wire Wire Line
	6300 1200 6300 1300
Wire Wire Line
	6300 1300 6200 1300
Connection ~ 6200 1300
Wire Wire Line
	6200 1300 6200 1150
Wire Wire Line
	9000 5300 9250 5300
Wire Wire Line
	9900 4850 9900 5300
Connection ~ 9900 5300
Wire Wire Line
	9900 5300 10150 5300
Wire Wire Line
	10000 4850 10000 5000
Connection ~ 10000 5000
Wire Wire Line
	10000 5000 10150 5000
$Comp
L Connector:Barrel_Jack_Switch J4
U 1 1 5DC26B60
P 8700 5200
F 0 "J4" H 8757 5517 50  0000 C CNN
F 1 "Barrel_Jack_Switch" H 8757 5426 50  0000 C CNN
F 2 "open-nixie_baseModule:DC_Jack_Vertical" H 8750 5160 50  0001 C CNN
F 3 "~" H 8750 5160 50  0001 C CNN
	1    8700 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 5200 9250 5200
Wire Wire Line
	9250 5200 9250 5300
Connection ~ 9250 5300
Wire Wire Line
	9250 5300 9550 5300
$Comp
L Transistor_BJT:BC817 Q3
U 1 1 5DBFE490
P 4300 2150
F 0 "Q3" H 4491 2196 50  0000 L CNN
F 1 "BC817" H 4491 2105 50  0000 L CNN
F 2 "open-nixie_baseModule:SOT-23_Handsoldering" H 4500 2075 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC817.pdf" H 4300 2150 50  0001 L CNN
	1    4300 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 5DC24D8D
P 7100 1400
F 0 "C6" H 7215 1446 50  0000 L CNN
F 1 "100n" H 7215 1355 50  0000 L CNN
F 2 "open-nixie_baseModule:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7138 1250 50  0001 C CNN
F 3 "~" H 7100 1400 50  0001 C CNN
	1    7100 1400
	1    0    0    -1  
$EndComp
Connection ~ 7100 1250
Wire Wire Line
	7100 1250 7200 1250
Connection ~ 7100 1550
Wire Wire Line
	7100 1550 6750 1550
Wire Wire Line
	9150 3050 9150 2950
Wire Wire Line
	9150 2650 9150 2300
Wire Wire Line
	8900 2300 9150 2300
Connection ~ 9150 2300
Wire Wire Line
	9150 2300 9350 2300
$Comp
L Device:R R19
U 1 1 5E99FD99
P 2700 3300
F 0 "R19" H 2770 3346 50  0000 L CNN
F 1 "2k2" H 2770 3255 50  0000 L CNN
F 2 "open-nixie_baseModule:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2630 3300 50  0001 C CNN
F 3 "~" H 2700 3300 50  0001 C CNN
	1    2700 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 3150 2700 3100
Connection ~ 2700 3100
Wire Wire Line
	2700 3450 3200 3450
Connection ~ 3200 3450
Wire Wire Line
	3200 3450 3200 3550
$EndSCHEMATC
