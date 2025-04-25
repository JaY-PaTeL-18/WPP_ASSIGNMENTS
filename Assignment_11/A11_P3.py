import pandas as pd

# Example data
asking_prices = pd.Series([15000, 18000, 12000, 22000, 17000])
fair_prices = pd.Series([16000, 17500, 13000, 21000, 18000])

# Find indices where asking_price < fair_price
good_deal_indices = list((asking_prices < fair_prices).loc[lambda x: x].index)

print(good_deal_indices)
