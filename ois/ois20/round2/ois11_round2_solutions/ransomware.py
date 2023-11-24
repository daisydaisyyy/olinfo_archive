#!/usr/bin/env python3

# Starting from position 0, determines the (unique) match and advances
# the current position by the length of the matched codeword.

def matching_idx(text, codes):
    for idx, code in enumerate(codes):
        if text.startswith(code):
            return idx
    # No matching found, should never happen
    assert(False)

N = int(input().strip())
contacts = []
codes = []
for _ in range(N):
    contacts.append(input().strip())
for _ in range(10):
    codes.append(input().strip())
for contact in contacts:
    start = 0
    end = len(contact)
    while start < end:
        idx = matching_idx(contact[start:], codes)
        print(idx, end="")
        start += len(codes[idx])
    assert(start == end)
    print()
