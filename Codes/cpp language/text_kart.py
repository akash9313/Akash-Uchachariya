# Text-based Kart Battle (No Dependencies)
import random

karts = {
    "Player 1": {"health": 3, "items": ["Boost", "Missile"]},
    "Player 2": {"health": 3, "items": ["Shield", "Triple Shot"]}
}

def battle():
    while True:
        for attacker, defender in [("Player 1", "Player 2"), ("Player 2", "Player 1")]:
            print(f"\n{attacker}'s turn!")
            action = input("Choose action [attack/item]: ").lower()
            
            if action == "attack":
                damage = random.randint(0, 1)
                karts[defender]["health"] -= damage
                print(f"{attacker} {'hits' if damage else 'misses'} {defender}!")
            elif action == "item":
                item = random.choice(karts[attacker]["items"])
                print(f"Used {item}: {apply_item(attacker, defender, item)}")
            
            print_status()
            
            if karts[defender]["health"] <= 0:
                print(f"\n{attacker} wins!")
                return

def apply_item(user, target, item):
    effects = {
        "Boost": f"{user} gains +1 speed!",
        "Missile": f"{target} takes 1 damage!",
        "Shield": f"{user} blocks next attack!",
        "Triple Shot": f"{user} fires three projectiles!"
    }
    return effects.get(item, "No effect")

def print_status():
    print("\n--- Battle Status ---")
    for name, stats in karts.items():
        print(f"{name}: {'❤' * stats['health']} | Items: {', '.join(stats['items'])}")

battle()
