import random #used so that i can select a random word from the list
print("Welcome to the hangman game, You have 5 guesses") #introduction

word = ["cyber", "security", "antivirus"]   #this list contains words that has to be guessed by the player
word1 = [] #This list will be used later , to show the player how many letters are missing and what letter he got correct so far
random_word = random.choice(word) #pick a random item from the list




for letter in random_word:      #adds underscore to the empty list located in line 5. (The underscore number is dependent on how many letters there are in the word)
    word1.append("_")


counter = 0
#The "game" function, will tell you if the guesses are right or not"
def game( random_word, counter):
    game_over = False
    while not game_over:
        user_input = input("Guess a letter: ").lower()
        for i in range(len(random_word)):      #This loop will verify if you did right guesses or not

            if user_input == random_word[i]:
                print("right")
                word1[i]= [user_input]      #This list contains underscores which will be replaced by letters that the player correctly guesses

            else:
                print("wrong")
        if user_input not in random_word:       #this IF statement is used, to keep track of number of incorrect guesses done by the player
            counter += 1
            if counter > 4:             #After 5 incorrect guesses the game will stop by setting the game_over parameter to TRUE
                print(f"You finished your number of possible attempts which is 5. The secret word is {random_word}")
                game_over = True
        print(word1)

        if "_" not in word1:        #If there are no underscores left then the player wins
            print("You win")
            game_over = True


game(random_word, counter)  #this will call the function game(in line 17)


