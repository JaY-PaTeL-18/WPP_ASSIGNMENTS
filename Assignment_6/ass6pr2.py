'''Write a class called Rock_paper_scissors that implements the logic of the game Rock paper-
scissors. For this game the user plays against the computer for a certain number of rounds. 
Your class should have fields for the how many rounds there will be, the current round number, 
and the number of wins each player has. There should be methods for getting the computer’s 
choice, finding the winner of a round, and checking to see if someone has one the (entire) 
game. You may want more methods.'''

import random
class Rock_Paper_scissors:
    #init methode to define all class variables
    def __init__(self, round):
        self.round=round
        self.current_round=0
        self.com_wins=0
        self.player_wins=0
        self.choices=["rock","paper","scissor"]
    #it will give choice of computer randomely
    def com_choice(self):
        return random.choice(self.choices)
    #it will decide the result of one round
    def winner_of_round(self,user_choice,com_choice):
        if(user_choice==com_choice):
            return "draw"
        elif (user_choice=="rock" and com_choice=="scissor") or \
            (user_choice=="paper" and com_choice=="rock") or \
            (user_choice=="scissor" and com_choice=="paper"):
            self.player_wins+=1
            return "win"
        else:
            self.com_wins+=1
            return "lose"
    #it will play n number of rounds using winner_of_round method
    def playing_game(self):
        print("WELCOME to the rock , paper , scissor Game")
        print(f"Best of {self.round} rounds will be the winner")
        while(self.current_round<self.round):
            print(f"ROUND {(self.current_round)+1} :")
            user_choice=input("Chose rock,paper or scissor : ").lower()
            if user_choice not in self.choices:
                print("Input is wrong,Try Again!")
                continue
            com_choice=self.com_choice()
            print(f"Computer chose {com_choice}")
            winner=self.winner_of_round(user_choice,com_choice)
            if winner=="draw":
                print("It's Draw.")
            elif winner=="win":
                print("You Won This Round.")
            elif winner=="lose":
                print("Computer Won This Round.")
            self.current_round+=1
        self.final_winner()
    
    #will decide final winner
    def final_winner(self):
        print("Game over...")
        print(f"Final Score: you : {self.player_wins} | computer : {self.com_wins}")
        if self.player_wins>self.com_wins:
            print("You won the game.")
        elif self.com_wins>self.player_wins:
            print("Computer won the game.")
        elif self.com_wins==self.player_wins:
            print("It's Draw...")

    
'''Main Function'''
round=int(input("Enter Number Of Round You Want To Play : "))
game = Rock_Paper_scissors(round)
game.playing_game()
