import pandas as pd
import itertools

# Sample concert data
concerts = pd.DataFrame({
    'artist': ['A', 'A', 'B', 'A', 'C'],
    'venue': ['X', 'Y', 'X', 'X', 'Y'],
    'date': pd.to_datetime(['2023-01-15', '2023-01-20', '2023-02-10', '2023-01-25', '2023-02-05'])
})

# Given Series of all possible artists and venues
artists = pd.Series(['A', 'B', 'C'])
venues = pd.Series(['X', 'Y'])

# Step 1: Create 'year-month' column
concerts['year_month'] = concerts['date'].dt.to_period('M').astype(str)

# Step 2: Group and count concerts per (year_month, artist, venue)
grouped = concerts.groupby(['year_month', 'artist', 'venue']).size().reset_index(name='count')

# Step 3: Generate full cartesian product of year_months, artists, venues
all_months = concerts['year_month'].unique()
all_combos = pd.MultiIndex.from_product(
    [all_months, artists, venues],
    names=['year_month', 'artist', 'venue']
).to_frame(index=False)

# Step 4: Merge actual counts into full grid
full_data = all_combos.merge(grouped, on=['year_month', 'artist', 'venue'], how='left').fillna(0)

# Step 5: Pivot to wide format
wide = full_data.pivot_table(
    index='year_month',
    columns=['artist', 'venue'],
    values='count',
    fill_value=0
)

# Optional: flatten multi-index columns
wide.columns = [f'{a}_{v}' for a, v in wide.columns]
wide = wide.reset_index()

print(wide)
