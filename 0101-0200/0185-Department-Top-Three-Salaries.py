import pandas as pd

def top_three_salaries(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    df = pd.merge(
        employee,
        department,
        how="inner",
        left_on="departmentId",
        right_on="id"
    )
    df = df.drop(columns=["id_y"])
    df = df.rename(columns={
        "id_x" : "id",
        "name_x" : "name", 
        "name_y" : "dept_name"
    })
    result_df = pd.DataFrame(columns=["Department", "Employee", "Salary"])
    unique_departments = department['name'].unique()
    for dep in unique_departments:
        temp = df[df["dept_name"] == dep]
        unique_salaries = temp['salary'].drop_duplicates().sort_values(ascending=False).head(3)
        temp_top = temp[temp['salary'].isin(unique_salaries)]
        rows = temp_top[['dept_name', 'name', 'salary']].rename(
            columns={'dept_name': 'Department', 'name': 'Employee', 'salary': 'Salary'}
        )
        result_df = pd.concat([result_df, rows])
    return result_df
