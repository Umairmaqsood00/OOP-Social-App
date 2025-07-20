#include <iostream>
#include "utils.h"
using namespace std;

void App::run()
{
	cout << "Welcome to our Social Media app!" << endl;
	int menuChoice;
	bool isLoggedIn = false;
	string loggedInUser;

	do
	{
		cout << "\n 1.  Signup\n 2. Signin\n 0. Exit\n Enter your choice: ";
		cin >> menuChoice;
		cin.ignore();

		if (menuChoice == 1)
		{
			string newUsername, newPassword;
			cout << "Enter a new username: ";
			getline(cin, newUsername);
			cout << "Enter a new password: ";
			getline(cin, newPassword);
			if (User::signup(newUsername, newPassword))
			{
				cout << "Signup successful! You can now sign in." << endl;
			}
			else
			{
				cout << "That username already exists. Please try another." << endl;
			}
		}
		else if (menuChoice == 2)
		{
			string username, password;
			cout << "Enter your username: ";
			getline(cin, username);
			cout << "Enter your password: ";
			getline(cin, password);
			if (User::signin(username, password))
			{
				cout << "Signin successful!" << endl;
				isLoggedIn = true;
				loggedInUser = username;
				break;
			}
			else
			{
				cout << "Invalid username or password. Please try again." << endl;
			}
		}
	} while (menuChoice != 0 && !isLoggedIn);

	if (!isLoggedIn)
	{
		cout << "Goodbye!" << endl;
		return;
	}

	do
	{
		cout << "\n1. Create Post" << endl;
		cout << "2. Add Comment" << endl;
		cout << "3. View Posts" << endl;
		cout << "4. View Comments" << endl;
		cout << "5. Like a Post" << endl;
		cout << "6. Set/Edit Bio" << endl;
		cout << "7. View My Profile" << endl;
		cout << "0. Logout" << endl;
		cout << "Enter your choice: ";
		cin >> menuChoice;
		cin.ignore();

		if (menuChoice == 1)
		{
			string postContent;
			cout << "Enter your post content: ";
			getline(cin, postContent);
			Post newPost(loggedInUser, postContent);
			newPost.saveToFile();
			cout << "Post created!" << endl;
		}
		else if (menuChoice == 2)
		{
			vector<Post> allPosts = Post::loadAll();
			if (allPosts.empty())
			{
				cout << "No posts available to comment on." << endl;
			}
			else
			{
				cout << "All Posts:" << endl;
				for (int i = 0; i < allPosts.size(); ++i)
					allPosts[i].display(i);
				int postIndex;
				cout << "Enter the index of the post you want to comment on: ";
				cin >> postIndex;
				cin.ignore();
				if (postIndex >= 0 && postIndex < allPosts.size())
				{
					string commentText;
					cout << "Enter your comment: ";
					getline(cin, commentText);
					Comment newComment(postIndex, loggedInUser, commentText);
					newComment.saveToFile();
					cout << "Comment added!" << endl;
				}
				else
				{
					cout << "Invalid post index." << endl;
				}
			}
		}
		else if (menuChoice == 3)
		{
			vector<Post> allPosts = Post::loadAll();
			cout << "All Posts:" << endl;
			for (int i = 0; i < allPosts.size(); ++i)
				allPosts[i].display(i);
		}
		else if (menuChoice == 4)
		{
			vector<Comment> allComments = Comment::loadAll();
			cout << "All Comments:" << endl;
			for (int i = 0; i < allComments.size(); ++i)
				allComments[i].display();
		}
		else if (menuChoice == 5)
		{
			vector<Post> allPosts = Post::loadAll();
			cout << "All Posts:" << endl;
			for (int i = 0; i < allPosts.size(); ++i)
				allPosts[i].display(i);
			int postIndex;
			cout << "Enter the index of the post you want to like: ";
			cin >> postIndex;
			cin.ignore();
			if (postIndex >= 0 && postIndex < allPosts.size())
			{
				if (Post::hasUserLiked(postIndex, loggedInUser))
				{
					cout << "You have already liked this post." << endl;
				}
				else
				{
					Post::likePost(postIndex, loggedInUser);
					cout << "You liked the post!" << endl;
				}
			}
			else
			{
				cout << "Invalid post index." << endl;
			}
		}
		else if (menuChoice == 6)
		{
			User user(loggedInUser, "");
			string bio;
			cout << "Enter your bio: ";
			getline(cin, bio);
			user.setBio(bio);
			user.saveBioToFile();
			cout << "Bio saved!" << endl;
		}
		else if (menuChoice == 7)
		{
			User user(loggedInUser, "");
			user.loadBioFromFile();
			cout << "Username: " << user.getUsername() << endl;
			cout << "Bio: " << user.getBio() << endl;
			vector<Post> allPosts = Post::loadAll();
			vector<Comment> allComments = Comment::loadAll();
			cout << "\nYour Posts:" << endl;
			int userPostCount = 0;
			for (int i = 0; i < allPosts.size(); ++i)
			{
				if (allPosts[i].author == loggedInUser)
				{
					cout << "[" << i << "] " << allPosts[i].author << ": " << allPosts[i].content;
					int likes = Post::getLikeCount(i);
					cout << " [Likes: " << likes << "]" << endl;

					cout << "  Comments:" << endl;
					bool hasComment = false;
					for (int j = 0; j < allComments.size(); ++j)
					{
						if (allComments[j].postIndex == i)
						{
							cout << "    " << allComments[j].author << ": " << allComments[j].text << endl;
							hasComment = true;
						}
					}
					if (!hasComment)
						cout << "    No comments yet." << endl;
					userPostCount++;
				}
			}
			if (userPostCount == 0)
				cout << "No posts yet." << endl;
		}
	} while (menuChoice != 0);
	cout << "Logged out. Goodbye!" << endl;
}

int main()
{
	App app;
	app.run();
}
