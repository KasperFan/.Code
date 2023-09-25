import hashlib

def get_sha256(input_string):
    sha256 = hashlib.sha256()
    sha256.update(input_string.encode('utf-8'))
    return sha256.hexdigest()

# Example usage
input_string = input()
print(get_sha256(input_string))