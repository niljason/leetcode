import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    temp = employee.sort_values(by="salary", ascending=False)
    unique_values = temp['salary'].unique()
    secondHighest = None
    print(unique_values)
    if len(unique_values) > 1:
        secondHighest = unique_values[1]
    return pd.DataFrame({"SecondHighestSalary": [secondHighest]})
