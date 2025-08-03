import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    unique_values = employee.sort_values(by="salary", ascending=False)["salary"].unique()
    if len(unique_values) < N or N < 1: 
        return pd.DataFrame({f"getNthHighestSalary({N})": [None]})
    else:
        return pd.DataFrame({f"getNthHIghestSalary({N})": [unique_values[N-1]]})
