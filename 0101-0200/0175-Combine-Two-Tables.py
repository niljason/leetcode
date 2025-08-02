import pandas as pd

def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    df = pd.DataFrame.merge(
        person,
        address,
        how="left",
        on="personId"
    )
    df = df[["firstName", "lastName", "city", "state"]]
    return df
