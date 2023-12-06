import random

def juego():
    númeroSecreto = random.randint(1, 100)
    intentos = 0
    intentosMáximos = 5

    
    print("Estoy pensando en un número del 1 al 100. ¿Podés adivinarlo?")

    while intentos < intentosMáximos:
        númeroElegido = int(input("Introduzca el número elegido: "))

        if númeroElegido < númeroSecreto:
            print("Muy bajo! Pruebe un número más alto.")
        elif númeroElegido > númeroSecreto:
            print("Muy alto! Pruebe un númeromás bajo.")
        else:
            print(f"Felicidades! ha adivinado el número ({númeroSecreto}) en {intentos + 1} intentos!")
            return

        intentos += 1

    print(f"Se te acabaron los intentos! El número en el que estaba pensando es: {númeroSecreto}.")

juego()