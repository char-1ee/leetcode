# Read from the file file.txt and output all valid phone numbers to stdout.

# awk: `\d` is replaced by [0-9]
awk '/^(\([0-9]{3}\) |[0-9]{3}-)[0-9]{3}-[0-9]{4}$/' file.txt

# sed: `\d` is replaced by [0-9]
sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt

# grep
grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt