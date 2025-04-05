<h1> mars-TASK-1</h1>

## Installing ubuntu on windows.
It was very interesting task to install ubuntu on windows, i refered from youtube videos and also read 
README file given by the club ,Through all these sources i finally got installed ubuntu os.
[See Documentation of my experience:](docs/light_dose.docx)

## How I started learning terminal.
Earlier i knew some basic commands in terminal, by referring the links given in the task#1.
I went through all the commands and tried to promt in terminal and learnt bash language basic
creating sh files to run those commands.For the light dose questions,using bash language
i completed the problems.



## Learning github
Initailly i didn't have the github account,so i created new account and new repository to do that I
got full informationthrough aiand follewed those steps to get that.

<a href="https://youtu.be/RGOj5yH7evk?si=4kOZL6dJ7u6WvJij" target="_blank">git and github tutorials</a>


## Pushing the files into github 
I tried several times to push the files into my github repository from terminal, at i succeeded to push those 
files into my repository. you can see my repository , it is filled with demmy files in it,i was just trying.
I watched several youtube videos, used ai to do this.


## In solving mid dose problems.
I used ready insatlled vs code in laptop  to write the codes in c language.
From first I had a basic idea about vs code , it was more familer to get started with that.
it was provides easy options to push the files into github repository from its terminal.


### Euclidean Distance Formula (2D).
This formula is used in firt question , to calculated the extra distance to get offseted to the orignal
of the given distance so that rover rotates 360 on the red point with it centre  dove it.
e.g: sqrt(pow(x,2)+pow(y,2)).
#### q1:
I just corrected the error of distacne 55 , by adding the error distance to x or y or even both using 
euclidean distance formula and converted and divided it to x and y axis separately and added to the orignal 
components.


### Morse code learning
It was given in the question to convert the  morse code to normal high level language.
i saw a toutube video, got a brief idea about it.i just included the morse codelibrary manually as a array
of list and give a coe in such a way that it should compare each of them , one code bye code and decode to the 
matching normal letter in the library.

reference:<a href="https://youtu.be/D8tPkb98Fkk?si=8goNVhVYXhADC19y" target="_blank">Morse code decoding</a>

### Gimbal lock
Gimbal lock is a situation that occurs in 3D space when using Euler angles to represent orientation. 
It happens when two of the three rotation axes in a 3-axis gimbal system align,
causing a loss of one degree of freedom in rotation.

reference:reference:<a href="https://youtu.be/zc8b2Jo7mno?si=OeacWPNaYtOUJLDY" target="_blank">Morse code decoding</a>

The Problem with Euler Angles:
Euler angles rotate around one axis at a time (e.g., yaw → pitch → roll).
Each rotation affects the frame of reference for the next.
If two axes line up (like pitch rotates 90°), you lose one degree of freedom → gimbal lock.

To resolve this , we can used QUATERNIOUS system of 4-D that has one scalar part extra and other three vector parts.

#### q5: Approach.
At first given degree angles are converted to radians the the they are
made half angled.finally by using the formula, 3D rotations  are converted to 4D rotations.

conversion formula of 3-D EULER SYSTEM to 4-D QUATERNIOUS SYSTEM .
qw = cos(ϕ/2) * cos(θ/2) * cos(ψ/2) + sin(ϕ/2) * sin(θ/2) * sin(ψ/2)
qx = sin(ϕ/2) * cos(θ/2) * cos(ψ/2) - cos(ϕ/2) * sin(θ/2) * sin(ψ/2)
qy = cos(ϕ/2) * sin(θ/2) * cos(ψ/2) + sin(ϕ/2) * cos(θ/2) * sin(ψ/2)
qz = cos(ϕ/2) * cos(θ/2) * sin(ψ/2) - sin(ϕ/2) * sin(θ/2) * cos(ψ/2)









​






