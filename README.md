# OOP Social App (C++ Console Project)
This is a beginner-friendly, object-oriented C++ console application that simulates a simple social media platform. Users can sign up, sign in, create posts, comment, like posts, and manage their profile bio—all through a text-based menu.
## Features
Signup & Signin: Create a new account or log in with your username and password.
Create Post: Share your thoughts with others.
Add Comment: Comment on any post.
View Posts: See all posts made by users.
View Comments: See all comments on all posts.
Like a Post: Like any post (one like per user per post).
Set/Edit Bio: Add or update your personal bio.
View My Profile: See your username, bio, all your posts, their like counts, and comments on your posts.

### How It Works
All user credentials are stored in login.txt.
User bios are stored in user.txt.
Posts are stored in feed.txt.
Comments are stored in comments.txt and are linked to posts by index.
Likes are stored in likecom.txt.

### File Structure
utils.h — Contains all class definitions (User, Post, Comment, App).
utils.cpp — Contains the main logic and menu system.
login.txt — Stores usernames and passwords.
user.txt — Stores usernames and bios.
feed.txt — Stores posts.
comments.txt — Stores comments (with post index, author, and text).
likecom.txt — Stores likes (with post index and username).
