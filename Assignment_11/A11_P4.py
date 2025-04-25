import pandas as pd
import numpy as np

# Example DataFrame
df = pd.DataFrame({
    'John': [True, False, True, False, True, True, False, True, False, False],
    'Judy': [False, False, True, True, True, False, False, True, False, True]
})

# Step 1: Identify party days
party_days = df['John'] & df['Judy']

# Step 2: Create an array to hold the days till next party
days_til_party = np.full(len(df), np.inf)

# Step 3: Track the index of the next party (going backward)
next_party_idx = -1
for i in reversed(range(len(df))):
    if party_days[i]:
        next_party_idx = i
        days_til_party[i] = 0
    elif next_party_idx != -1:
        days_til_party[i] = next_party_idx - i

# Convert to integer, use a large value like 9999 if there's no future party
df['days_til_party'] = np.where(np.isinf(days_til_party), 9999, days_til_party.astype(int))

print(df)
