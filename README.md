# hang_man

A simple **Hangman Game** implemented in C language.  
The player tries to guess the secret word by entering letters or guessing the full word. Each wrong guess draws a part of the hangman until the player runs out of tries.

---

## 📌 Features

- Terminal-based Hangman drawing.
- Guess by letter or by full word.
- Case-insensitive input (e.g., `A` = `a`).
- Clear screen between rounds for a better experience.
- Works on both Linux and Windows (with minor adjustments).

---

## 🧠 How the Game Works

1. Player 1 enters the **secret word**.
2. The screen is cleared so Player 2 can start guessing.
3. Player 2:
   - Enters **one letter** at a time to try revealing the word.
   - Or tries to guess the **whole word**.
4. For each wrong guess, a part of the hangman is drawn.
5. The game ends when:
   - The player **guesses the word**, or
   - The hangman drawing is completed (0 tries left).