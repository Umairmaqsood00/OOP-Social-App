# 🌟 OOP Social App (C++ Console Project)

Welcome to the **OOP Social App** — a beginner-friendly C++ console application that simulates a basic social media platform using core Object-Oriented Programming concepts.

---

## 🚀 Features

- **Signup & Signin**  
  Create a new account or log in using your username and password.

- **Create Post**  
  Share your thoughts with others in the community.

- **Add Comment**  
  Comment on any post made by users.

- **View Posts**  
  Browse all posts shared by users.

- **View Comments**  
  See all comments linked to any post.

- **Like a Post**  
  Like a post (one like per user per post is allowed).

- **Set/Edit Bio**  
  Add or update your personal bio.

- **View My Profile**  
  See your username, bio, all your posts, likes, and comments received.

---

## 🛠️ How It Works

The app uses file-based storage to simulate a database:

- `login.txt` → Stores usernames and passwords  
- `user.txt` → Stores usernames and bios  
- `feed.txt` → Stores all user posts  
- `comments.txt` → Stores comments (linked by post index)  
- `likecom.txt` → Stores likes (linked by post index and user)

---

## 📁 File Structure

| File Name        | Description                                          |
|------------------|------------------------------------------------------|
| `utils.h`        | Contains all class definitions (`User`, `Post`, `Comment`, `App`) |
| `utils.cpp`      | Contains the core logic and menu-driven system       |
| `login.txt`      | Stores user credentials                              |
| `user.txt`       | Stores user bios                                     |
| `feed.txt`       | Stores posts shared by users                         |
| `comments.txt`   | Stores comments along with their post references     |
| `likecom.txt`    | Stores information about likes on posts              |

---

## 📌 Requirements

- C++ compiler (g++, clang++, etc.)
- Command-line terminal (Windows CMD, Terminal, etc.)


