# Who
* Alan Moy
* Jonathan Wehrend
* Austin Glaser
* Joseph Vostrejs

# Title: Outletify

# Description
Outletify provides two key features: energy usage tracking, and home
automation. Two distinct hardware components will make up a single Outletify
system. Microcontrollers integrate with outlets to allow for low level control
and usage detection, and a central server will be the main point of control for
all microcontrollers. Energy usage tracking features will monitor and log the
times outlets are in use, and the server will collect data and present it to
the user with straightforward graphics and statistics over a web interface.
This same web application will also serve as a hub for all home automation
capabilities, allowing the user to control and automate household activities
and appliances. By scheduling regular tasks and logging historical usage,
Outletify will grant users finer control over their house - what's running,
and what isn't.

# Vision statement
Outletify is the simplest way to manage and monitor all the household
technology you depend on. Lower your bills, reduce your environmental
footprint, and make your life easier by leaving menial tasks to the machines.

# Motivation
Many people today are concerned with managing their energy usage, whether
motivated by their utility bills, addressing climate change, or both. We are
developing Outletify to address this issue. By creating an affordable,
easily-installed and well-supoprted device to track power usage, we can allow
more people to maximize their energy efficiency.

# Risks
-   Risk: **Hardware component**
    -   By incorporating a hardware component into our project, we have a
        necessary increase in scope. We will need extra tools to program and
        debug our devices, and there's up-front work required before we can move
        into software development proper
    -   Mitigation:
        -   We can decouple the sections of our project by developing a sensor
            emulator that can run on a personal computer. This will allow the
            backend and database-level development to proceed regardless of the
            hardware state, as well as allowing a fallback for demonstration if
            the end-of-semester deadlines proves too ambitious
        -   We have two team members with embedded hardware experience.
        -   We will build our demonstration hardware primarly (or exclusively)
            from off-the-shelf components, to avoid the extra time and expense
            incurred when building a custom circuit board
-   Risk: **Database Management**
    -   None of our current group members have experience with database usage.
        We plan to use a database to store usage history.
    -   Mitigation:
        -   We plan to use the professor and TAs as resources
        -   We will limit the complexity of our database to facilitate debugging
        -   We can fall back to a simpler but less scalable option for
            demonstration purposes (i.e. storing data as simple text files)
-   Risk: **Schedule**
    -   This project necessarily has a hard deadline of the end of the semester;
        any slippage will mean that come demonstration time we will have to
        demonstrate a partially functional product
    -   Mitigation:
        -   We will focus on early and partial functionality, so that at any
            point we are capable of demonstrating some subset of our
            requirements.
        -   To that end, we will minimize our features' dependence on one
            another (to the extent that is possible) so that it's more feasible
            to implement them in parallel.

# VCS
### Github
* https://github.com/austinglaser/csci3308-project

# Requirements
![User Requirements](req_user.png)
![Functional Requirements](req_functional.png)
![Nonfunctional Requirements](req_nonfunctional.png)

# Methodology
* Agile

# Project Tracking software
### Trello
* https://trello.com/methodsandtools

# Project plan
![Project Plan in Trello](trello.png)

