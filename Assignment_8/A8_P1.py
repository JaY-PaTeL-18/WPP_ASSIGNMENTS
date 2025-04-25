def decode_message(encoded_message):
    def decode_ways(s, index, path, result):
        if index == len(s):
            result.append(path)
            return
        if s[index] == '0':
            return
        decode_ways(s, index + 1, path + chr(int(s[index]) + ord('A') - 1), result)
        if index + 1 < len(s) and int(s[index:index + 2]) <= 26:
            decode_ways(s, index + 2, path + chr(int(s[index:index + 2]) + ord('A') - 1), result)

    result = []
    decode_ways(encoded_message, 0, "", result)
    return result

encoded_message = input("Enter the encoded message: ")
decoded_messages = decode_message(encoded_message)
for message in decoded_messages:
    print(message)