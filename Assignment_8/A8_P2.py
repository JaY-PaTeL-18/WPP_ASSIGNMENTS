import re

def tokenize(text):
    # Define regex patterns
    patterns = {
        'punctuation': r'[.,!?;:()\"\'-]',
        'date': r'\b\d{1,2}/\d{1,2}/\d{2,4}\b',
        'url': r'https?://[^\s]+',
        'email': r'\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b',
        'number': r'\b\d{1,3}(,\d{3})*(\.\d+)?(/\d+)?\b',
        'username': r'@\w+',
        'gujarati_word': r'[\u0A80-\u0AFF]+'
    }

    # Combine all patterns into one
    combined_pattern = '|'.join(f'(?P<{key}>{pattern})' for key, pattern in patterns.items())

    # Tokenize text
    tokens = []
    for match in re.finditer(combined_pattern, text):
        token_type = match.lastgroup
        token_value = match.group(token_type)
        tokens.append((token_type, token_value))

    return tokens

# Example usage
# use this text => "મારો ઈમેલ છે test@example.com અને મારી વેબસાઇટ છે https://example.com. આજે તારીખ 12/10/2023 છે. @user123 1234"
text = input("Enter the text: ")
tokens = tokenize(text)
for token in tokens:
    print(token)