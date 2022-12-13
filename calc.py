binaryNumber = input('Enter a Binary number:')
dec_number = int(binaryNumber, 2)
print('The decimal conversion is:', dec_number)

binaryNumber = input('Enter a Binary number:')
dec_number = hex(int(binaryNumber, 2))
print('The hex conversion is:', dec_number)

dec_number = int(input('Enter a Decimal number:'))
binaryNumber = bin(dec_number)[2:]
print('The binary Number is:', binaryNumber)

dec_number = int(input('Enter a Decimal number:'))
binaryNumber = hex(dec_number)[2:]
print('The hex Number is:', binaryNumber)

hex_number = int(input('Enter Hex number:'), 16)
print('The decimal number is:', hex_number)

hex_number = input('Enter Hex number:')
hex_number = bin(int(hex_number, 16)).zfill(8)
print('The binary number is:', hex_number)