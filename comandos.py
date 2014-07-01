import serial;
ser = serial.Serial("COM16", 9600);
while(True):
	input_var = input("Comando: ");
	serial.write(input_var);
