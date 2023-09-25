# A simple base64 encoder and decoder in Python
# This is Bing, not an expert, so the code may not be perfect or efficient

# Define the base64 table as a string
base64_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

# Define a function to encode a string to base64


def base64_encode(s):
    # Convert the string to bytes using utf-8 encoding
    b = s.encode("utf-8")
    # Initialize an empty list to store the encoded bits
    bits = []
    # Loop through each byte in b
    for byte in b:
        # Convert the byte to an 8-bit binary string
        bin_str = format(byte, "08b")
        # Append the binary string to the bits list
        bits.append(bin_str)
    # Join the bits list into a single string
    bits = "".join(bits)
    # Initialize an empty list to store the encoded characters
    chars = []
    # Loop through the bits string with a step of 6
    for i in range(0, len(bits), 6):
        # Get a slice of 6 bits from the bits string
        chunk = bits[i:i+6]
        # If the chunk is less than 6 bits, pad it with zeros on the right
        if len(chunk) < 6:
            chunk = chunk + "0" * (6 - len(chunk))
        # Convert the chunk to an integer
        index = int(chunk, 2)
        # Get the corresponding character from the base64 table using the index
        char = base64_table[index]
        # Append the character to the chars list
        chars.append(char)
    # Join the chars list into a single string
    chars = "".join(chars)
    # If the length of chars is not a multiple of 4, pad it with "=" on the right
    if len(chars) % 4 != 0:
        chars = chars + "=" * (4 - len(chars) % 4)
    # Return the encoded string
    return chars

# Define a function to decode a base64 string to utf-8


def base64_decode(s):
    # Initialize an empty list to store the decoded bits
    bits = []
    # Loop through each character in s
    for char in s:
        # If the character is "=", skip it
        if char == "=":
            continue
        # Get the index of the character in the base64 table
        index = base64_table.index(char)
        # Convert the index to a 6-bit binary string
        bin_str = format(index, "06b")
        # Append the binary string to the bits list
        bits.append(bin_str)
    # Join the bits list into a single string
    bits = "".join(bits)
    # Initialize an empty list to store the decoded bytes
    bytes = []
    # Loop through the bits string with a step of 8
    for i in range(0, len(bits), 8):
        # Get a slice of 8 bits from the bits string
        chunk = bits[i:i+8]
        # Convert the chunk to an integer
        byte = int(chunk, 2)
        # Append the byte to the bytes list
        bytes.append(byte)
    # Convert the bytes list to a bytes object
    b = bytes(bytes)
    # Decode the bytes object to a utf-8 string
    s = b.decode("utf-8")
    # Return the decoded string
    return s

# Test the functions with some examples


print(base64_encode("Hello world!"))  # SGVsbG8gd29ybGQh

print(base64_decode("SGVsbG8gd29ybGQh"))  # Hello world!

# d2N0ZntiYXNlNjRfaXNfdmVyeV9lYXN5fQ==
print(base64_encode("wctf{base64_is_very_easy}"))

# wctf{base64_is_very_easy}
print(base64_decode("d2N0ZntiYXNlNjRfaXNfdmVyeV9lYXN5fQ=="))

key = input()

print(base64_decode(key))
print(base64_encode(key))