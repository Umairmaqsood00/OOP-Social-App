🌟 OOP Social App (C++ Console Project)
Welcome to the OOP Social App—a beginner-friendly, C++ console application that simulates a simple social media platform using Object-Oriented Programming concepts!

🚀 Features
Signup & Signin
Create a new account or log in with your username and password.

Create Post
Share your thoughts with others in the community.

Add Comment
Comment on any post.

View Posts
Browse all posts made by users.

View Comments
See all comments on any post.

Like a Post
Like any post (one like per user per post).

Set/Edit Bio
Add or update your personal bio.

View My Profile
View your username, bio, all your posts, their like counts, and comments on your posts.

🛠️ How It Works
User credentials are stored in login.txt
User bios are stored in user.txt
Posts are stored in feed.txt
Comments are stored in comments.txt (linked to posts by index)
Likes are stored in likecom.txt
📁 File Structure
File	Description
utils.h	All class definitions (User, Post, Comment, App)
utils.cpp	Main logic and menu system
login.txt	Stores usernames and passwords
user.txt	Stores usernames and bios
feed.txt	Stores posts
comments.txt	Stores comments (with post index, author, and text)
likecom.txt	Stores likes (with post index and username)
