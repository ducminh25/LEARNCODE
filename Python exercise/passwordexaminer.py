def check_password(password):
    score = 0
    if len(password) > 8 and any(char.islower() for char in password):
        score += 10
    if any(char.isupper() for char in password):
        score += 10
    if any(char.isdigit() for char in password):
        score += 20
    special_chars = "!@#$%^&*()-_=+[{]}|;:'\",<.>/?`~"
    if any(char in special_chars for char in password):
        score += 30
    if all([char.islower() for char in password]) and all([char.isupper() for char in password]) and all([char.isdigit() for char in password]) and all([char in special_chars for char in password]):
        score += 30
    seen = set()
    for i in range(2, len(password)):
        for j in range(len(password) - i + 1):
            substring = password[j:j+i]
            if substring in seen:
                score -= (10 * i * (password.count(substring) - 1))
            else:
                seen.add(substring)
    return score

def announce_rank(score):
    if score < 30:
        rank = "poor"
    elif score < 70:
        rank = "weak"
    else:
        rank = "strong"
    return rank

password = input("Enter your password: ")
score = check_password(password)

rank = announce_rank(score)

print(f"Your password has a security score of {score} and a security rank of {rank}.")