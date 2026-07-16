def count_upper_lower(s): 
    upper_count = 0
    lower_count = 0

    for i in s:
        if i.isupper():
            upper_count += 1 
        if i.islower():
            lower_count += 1
    return (upper_count, lower_count) 

s = input("Given string: ")

result = count_upper_lower(s)

print("Number of uppercase letters:", result[0])
print("Number of lowercase letters:", result[1])