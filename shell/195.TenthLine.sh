# Read from the file file.txt and output the tenth line to stdout.

# Solution 1: smartly use tail first to slice from 10th, which avoids 
# the case that less than 10 lines.

tail -n +10 file.txt | head -n 1

# Solution 2: my solution.

sed -n '10'p file.txt
