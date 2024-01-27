import re

def extract_emails_and_phones(text):
    # Define regex patterns for email and phone number extraction
    email_pattern = r'\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b'
    phone_pattern = r'\b(?:\+\d{1,2}\s?)?(?:\(\d{3}\)|\d{3})[-.\s]?\d{3}[-.\s]?\d{4}\b'

    # Find all matches in the text
    emails = re.findall(email_pattern, text)
    phones = re.findall(phone_pattern, text)

    return emails, phones

def main():
    # Read text from a file
    with open('sample_text.txt', 'r') as file:
        text = file.read()

    # Extract emails and phone numbers using regex
    extracted_emails, extracted_phones = extract_emails_and_phones(text)

    # Print the results
    print("Extracted Emails:")
    for email in extracted_emails:
        print(email)

    print("\nExtracted Phone Numbers:")
    for phone in extracted_phones:
        print(phone)

if __name__ == "__main__":
    main()

