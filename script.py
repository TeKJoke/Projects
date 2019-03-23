
import random

ran_num = random.randint(0, 10)

print('Guess a random number between 0 and 10')
num = input('Enter a number: ')

if num == ran_num:
    print('The number is correct')
elif num > 10 or num < 0:
    print('The number should be between 0 and 10!')
elif num < ran_num:
    print('The number should be bigger')
elif num > ran_num:
    print('The number should be smaller')
else:
    print('Error!!!')
