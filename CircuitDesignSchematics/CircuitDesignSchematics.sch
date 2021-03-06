EESchema Schematic File Version 4
LIBS:CircuitDesignSchematics-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "lun. 30 mars 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Switch:SW_DIP_x01 SW?
U 1 1 5DD22D5A
P 7050 2500
F 0 "SW?" V 7004 2630 50  0000 L CNN
F 1 "SW_DIP_x01" V 7095 2630 50  0000 L CNN
F 2 "" H 7050 2500 50  0001 C CNN
F 3 "~" H 7050 2500 50  0001 C CNN
	1    7050 2500
	0    1    1    0   
$EndComp
Text Label 3950 2850 1    60   ~ 0
Vin
Text Label 4350 2850 1    60   ~ 0
IOREF
Text Label 3900 3900 0    60   ~ 0
A0
Text Label 3900 4000 0    60   ~ 0
A1
Text Label 3900 4100 0    60   ~ 0
A2
Text Label 3900 4200 0    60   ~ 0
A3
Text Label 3900 4300 0    60   ~ 0
A4(SDA)
Text Label 3900 4400 0    60   ~ 0
A5(SCL)
Text Label 5550 4400 0    60   ~ 0
0(Rx)
Text Label 5550 4200 0    60   ~ 0
2
Text Label 5550 4300 0    60   ~ 0
1(Tx)
Text Label 5550 4100 0    60   ~ 0
3(**)
Text Label 5550 4000 0    60   ~ 0
4
Text Label 5550 3900 0    60   ~ 0
5(**)
Text Label 5550 3800 0    60   ~ 0
6(**)
Text Label 5550 3700 0    60   ~ 0
7
Text Label 5550 3500 0    60   ~ 0
8
Text Label 5550 3400 0    60   ~ 0
9(**)
Text Label 5550 3300 0    60   ~ 0
10(**/SS)
Text Label 5550 3200 0    60   ~ 0
11(**/MOSI)
Text Label 5550 3100 0    60   ~ 0
12(MISO)
Text Label 5550 3000 0    60   ~ 0
13(SCK)
Text Label 5550 2800 0    60   ~ 0
AREF
NoConn ~ 4400 3000
Text Label 5550 2700 0    60   ~ 0
A4(SDA)
Text Label 5550 2600 0    60   ~ 0
A5(SCL)
Text Notes 5850 2400 0    60   ~ 0
Holes
Text Notes 3550 2150 0    60   ~ 0
Shield for Arduino that uses\nthe same pin disposition\nlike "Uno" board Rev 3.
$Comp
L Connector_Generic:Conn_01x08 P1
U 1 1 56D70129
P 4600 3300
F 0 "P1" H 4600 3750 50  0000 C CNN
F 1 "Power" V 4700 3300 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x08" V 4750 3300 20  0000 C CNN
F 3 "" H 4600 3300 50  0000 C CNN
	1    4600 3300
	1    0    0    -1  
$EndComp
Text Label 3650 3200 0    60   ~ 0
Reset
$Comp
L power:+3.3V #PWR01
U 1 1 56D70538
P 4150 2850
F 0 "#PWR01" H 4150 2700 50  0001 C CNN
F 1 "+3.3V" V 4150 3100 50  0000 C CNN
F 2 "" H 4150 2850 50  0000 C CNN
F 3 "" H 4150 2850 50  0000 C CNN
	1    4150 2850
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR02
U 1 1 56D707BB
P 4050 2750
F 0 "#PWR02" H 4050 2600 50  0001 C CNN
F 1 "+5V" V 4050 2950 50  0000 C CNN
F 2 "" H 4050 2750 50  0000 C CNN
F 3 "" H 4050 2750 50  0000 C CNN
	1    4050 2750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 56D70CC2
P 4300 4550
F 0 "#PWR03" H 4300 4300 50  0001 C CNN
F 1 "GND" H 4300 4400 50  0000 C CNN
F 2 "" H 4300 4550 50  0000 C CNN
F 3 "" H 4300 4550 50  0000 C CNN
	1    4300 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 56D70CFF
P 5300 4550
F 0 "#PWR04" H 5300 4300 50  0001 C CNN
F 1 "GND" H 5300 4400 50  0000 C CNN
F 2 "" H 5300 4550 50  0000 C CNN
F 3 "" H 5300 4550 50  0000 C CNN
	1    5300 4550
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 P2
U 1 1 56D70DD8
P 4600 4100
F 0 "P2" H 4600 3700 50  0000 C CNN
F 1 "Analog" V 4700 4100 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x06" V 4750 4150 20  0000 C CNN
F 3 "" H 4600 4100 50  0000 C CNN
	1    4600 4100
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P5
U 1 1 56D71177
P 5800 2050
F 0 "P5" V 5900 2050 50  0000 C CNN
F 1 "CONN_01X01" V 5900 2050 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" H 5721 2124 20  0000 C CNN
F 3 "" H 5800 2050 50  0000 C CNN
	1    5800 2050
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P6
U 1 1 56D71274
P 5900 2050
F 0 "P6" V 6000 2050 50  0000 C CNN
F 1 "CONN_01X01" V 6000 2050 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" H 5900 2050 20  0001 C CNN
F 3 "" H 5900 2050 50  0000 C CNN
	1    5900 2050
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P7
U 1 1 56D712A8
P 6000 2050
F 0 "P7" V 6100 2050 50  0000 C CNN
F 1 "CONN_01X01" V 6100 2050 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" V 6000 2050 20  0001 C CNN
F 3 "" H 6000 2050 50  0000 C CNN
	1    6000 2050
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P8
U 1 1 56D712DB
P 6100 2050
F 0 "P8" V 6200 2050 50  0000 C CNN
F 1 "CONN_01X01" V 6200 2050 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" H 6024 1972 20  0000 C CNN
F 3 "" H 6100 2050 50  0000 C CNN
	1    6100 2050
	0    -1   -1   0   
$EndComp
NoConn ~ 5800 2250
NoConn ~ 5900 2250
NoConn ~ 6000 2250
NoConn ~ 6100 2250
$Comp
L Connector_Generic:Conn_01x08 P4
U 1 1 56D7164F
P 5000 4000
F 0 "P4" H 5000 3500 50  0000 C CNN
F 1 "Digital" V 5100 4000 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x08" V 5150 3950 20  0000 C CNN
F 3 "" H 5000 4000 50  0000 C CNN
	1    5000 4000
	-1   0    0    -1  
$EndComp
Wire Notes Line
	3525 2225 4925 2225
Wire Notes Line
	4925 2225 4925 1875
Wire Wire Line
	4350 2850 4350 3100
Wire Wire Line
	4350 3100 4400 3100
Wire Wire Line
	4400 3300 4150 3300
Wire Wire Line
	4400 3500 4300 3500
Wire Wire Line
	4400 3600 4300 3600
Connection ~ 4300 3600
Wire Wire Line
	3950 3700 3950 2850
Wire Wire Line
	4050 3400 4050 2750
Wire Wire Line
	4150 3300 4150 2850
Wire Wire Line
	4400 4100 3900 4100
Wire Wire Line
	4400 4200 3900 4200
Wire Wire Line
	4400 4300 3900 4300
$Comp
L Connector_Generic:Conn_01x10 P3
U 1 1 56D721E0
P 5000 3000
F 0 "P3" H 5000 3550 50  0000 C CNN
F 1 "Digital" V 5100 3000 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x10" V 5150 3000 20  0000 C CNN
F 3 "" H 5000 3000 50  0000 C CNN
	1    5000 3000
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5200 3500 5550 3500
Wire Wire Line
	5200 3400 5550 3400
Wire Wire Line
	5200 3300 5550 3300
Wire Wire Line
	5200 3200 5550 3200
Wire Wire Line
	5200 3100 5550 3100
Wire Wire Line
	5200 3000 5550 3000
Wire Wire Line
	5200 2800 5550 2800
Wire Wire Line
	5200 2700 5550 2700
Wire Wire Line
	5200 2600 5550 2600
Wire Wire Line
	5200 4400 5550 4400
Wire Wire Line
	5200 4300 5550 4300
Wire Wire Line
	5200 3900 5550 3900
Wire Wire Line
	5200 2900 5300 2900
Wire Wire Line
	5300 2900 5300 4550
Wire Wire Line
	4300 3500 4300 3600
Wire Notes Line
	3500 1900 3500 4850
Wire Notes Line
	3500 4850 6200 4850
Wire Wire Line
	4400 3200 3650 3200
Text Notes 4700 3000 0    60   ~ 0
1
Wire Notes Line
	6200 2400 5700 2400
Wire Notes Line
	5700 2400 5700 1900
$Comp
L Device:LED D?
U 1 1 5DD1EBC1
P 7000 5250
F 0 "D?" H 6993 5466 50  0000 C CNN
F 1 "LED" V 6993 5375 50  0000 C CNN
F 2 "" H 7000 5250 50  0001 C CNN
F 3 "~" H 7000 5250 50  0001 C CNN
	1    7000 5250
	0    -1   -1   0   
$EndComp
$Comp
L Device:Buzzer BZ?
U 1 1 5DD1AB05
P 7350 3750
F 0 "BZ?" H 7502 3779 50  0000 L CNN
F 1 "Buzzer" H 7502 3688 50  0000 L CNN
F 2 "" V 7325 3850 50  0001 C CNN
F 3 "~" V 7325 3850 50  0001 C CNN
	1    7350 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 3700 5550 3700
Wire Wire Line
	4400 3700 3950 3700
$Comp
L fsr:FSR RF?
U 1 1 5DD627E3
P 2100 2900
F 0 "RF?" H 2198 2946 50  0000 L CNN
F 1 "FSR" H 2198 2855 50  0000 L CNN
F 2 "" H 2100 2650 50  0001 C TNN
F 3 "" H 2100 2550 50  0001 C TNN
	1    2100 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:R BuzzerRessistor
U 1 1 5DD66357
P 6750 3650
F 0 "BuzzerRessistor" V 6543 3650 50  0000 C CNN
F 1 "100" V 6634 3650 50  0000 C CNN
F 2 "" V 6680 3650 50  0001 C CIN
F 3 "~" H 6750 3650 50  0001 C CNN
	1    6750 3650
	0    1    1    0   
$EndComp
$Comp
L sensors:PIR_Motion_Sensor PIR?
U 1 1 5DD71F48
P 7750 3000
F 0 "PIR?" V 7697 3728 60  0000 L CNN
F 1 "PIR_Motion_Sensor" V 7803 3728 60  0000 L CNN
F 2 "" H 7750 3800 60  0000 C CNN
F 3 "" H 7750 3800 60  0000 C CNN
	1    7750 3000
	0    1    1    0   
$EndComp
$Comp
L Device:R FSRRessistor
U 1 1 5DD709C2
P 2100 2400
F 0 "FSRRessistor" H 2170 2446 50  0000 L CNN
F 1 "10K" H 2170 2355 50  0000 L CNN
F 2 "" V 2030 2400 50  0001 C CNN
F 3 "~" H 2100 2400 50  0001 C CNN
	1    2100 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 3600 4300 4550
Wire Wire Line
	4400 4400 3900 4400
$Comp
L sensors:DHT22_Temperature_Humidity TH?
U 1 1 5DD67A97
P 7250 4450
F 0 "TH?" V 7197 5328 60  0000 L CNN
F 1 "DHT22_Temperature_Humidity" V 7303 5328 60  0000 L CNN
F 2 "" H 7250 4450 60  0000 C CNN
F 3 "" H 7250 4450 60  0000 C CNN
	1    7250 4450
	0    1    1    0   
$EndComp
$Comp
L fsr:FSR RF?
U 1 1 5DD968C6
P 2100 4400
F 0 "RF?" H 2198 4446 50  0000 L CNN
F 1 "FSR" H 2198 4355 50  0000 L CNN
F 2 "" H 2100 4150 50  0001 C TNN
F 3 "" H 2100 4050 50  0001 C TNN
	1    2100 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:R FSRRessistor?
U 1 1 5DD968CC
P 2100 3900
F 0 "FSRRessistor?" H 2170 3946 50  0000 L CNN
F 1 "10K" H 2170 3855 50  0000 L CNN
F 2 "" V 2030 3900 50  0001 C CNN
F 3 "~" H 2100 3900 50  0001 C CNN
	1    2100 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 3650 6900 3650
Wire Wire Line
	6600 3650 5550 3650
Wire Wire Line
	5550 3650 5550 3700
Wire Wire Line
	6200 3000 6200 3800
Wire Wire Line
	5200 3800 6200 3800
$Comp
L power:GND #PWR?
U 1 1 5DD9F12F
P 7250 3850
F 0 "#PWR?" H 7250 3600 50  0001 C CNN
F 1 "GND" V 7255 3722 50  0000 R CNN
F 2 "" H 7250 3850 50  0001 C CNN
F 3 "" H 7250 3850 50  0001 C CNN
	1    7250 3850
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DD9FCBA
P 7750 2900
F 0 "#PWR?" H 7750 2650 50  0001 C CNN
F 1 "GND" V 7755 2772 50  0000 R CNN
F 2 "" H 7750 2900 50  0001 C CNN
F 3 "" H 7750 2900 50  0001 C CNN
	1    7750 2900
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DDA0796
P 7250 4600
F 0 "#PWR?" H 7250 4350 50  0001 C CNN
F 1 "GND" V 7255 4472 50  0000 R CNN
F 2 "" H 7250 4600 50  0001 C CNN
F 3 "" H 7250 4600 50  0001 C CNN
	1    7250 4600
	0    1    1    0   
$EndComp
Wire Wire Line
	2100 2750 2100 2650
Wire Wire Line
	2100 4250 2100 4150
Wire Wire Line
	2100 3400 2100 3050
Wire Wire Line
	2100 3400 2750 3400
Connection ~ 4050 3400
Wire Wire Line
	4050 3400 4400 3400
Connection ~ 4400 3400
Wire Wire Line
	4400 3400 4450 3400
Wire Wire Line
	4050 3400 3100 3400
Wire Wire Line
	2750 3400 2750 4550
Wire Wire Line
	2750 4550 2100 4550
Connection ~ 2750 3400
Wire Wire Line
	3000 3900 3000 2650
Wire Wire Line
	3000 2650 2100 2650
Wire Wire Line
	3000 3900 4400 3900
Connection ~ 4400 3900
Wire Wire Line
	4400 3900 4450 3900
Connection ~ 2100 2650
Wire Wire Line
	2100 2650 2100 2550
Connection ~ 2100 4150
Wire Wire Line
	2100 4150 2100 4050
$Comp
L power:GND #PWR?
U 1 1 5DDAC5DB
P 2100 2250
F 0 "#PWR?" H 2100 2000 50  0001 C CNN
F 1 "GND" H 2105 2077 50  0000 C CNN
F 2 "" H 2100 2250 50  0001 C CNN
F 3 "" H 2100 2250 50  0001 C CNN
	1    2100 2250
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DDB0FA5
P 2100 3800
F 0 "#PWR?" H 2100 3550 50  0001 C CNN
F 1 "GND" H 2105 3627 50  0000 C CNN
F 2 "" H 2100 3800 50  0001 C CNN
F 3 "" H 2100 3800 50  0001 C CNN
	1    2100 3800
	-1   0    0    1   
$EndComp
Wire Wire Line
	7050 2800 6300 2800
Wire Wire Line
	6300 2800 6300 4000
Wire Wire Line
	5200 4000 6300 4000
Wire Wire Line
	6400 4300 6400 5450
Wire Wire Line
	6400 5450 3100 5450
Wire Wire Line
	3100 5450 3100 3400
Wire Wire Line
	6400 4300 7250 4300
Connection ~ 3100 3400
Wire Wire Line
	3100 3400 2750 3400
Wire Wire Line
	7250 4400 6600 4400
Wire Wire Line
	6600 4400 6600 4100
Wire Wire Line
	5200 4100 6600 4100
Wire Wire Line
	7750 3000 6200 3000
Wire Wire Line
	7750 3100 6650 3100
Wire Wire Line
	6650 3100 6650 1400
Wire Wire Line
	6650 1400 3100 1400
Wire Wire Line
	3100 1400 3100 3400
Wire Wire Line
	3700 4150 3700 4000
Wire Wire Line
	3700 4000 4400 4000
Wire Wire Line
	2100 4150 3700 4150
$Comp
L Device:R LEDRessistor
U 1 1 5DD228CE
P 7000 4950
F 0 "LEDRessistor" H 7070 4996 50  0000 L CNN
F 1 "250" H 7070 4905 50  0000 L CNN
F 2 "" V 6930 4950 50  0001 C CNN
F 3 "~" H 7000 4950 50  0001 C CNN
	1    7000 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 4800 6200 4800
Wire Wire Line
	6200 4800 6200 4200
Wire Wire Line
	5200 4200 6200 4200
Text Notes 7500 7500 0    50   ~ 0
APSC 200 Section 206 Group 02 Circuit Schematics
$EndSCHEMATC
