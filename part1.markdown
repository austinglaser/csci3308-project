# Who
* Alan Moy
* Jonathan Wehrend
* Austin Glaser
* Joseph Vostrejs

# Title
Outletify

# Description
Automation/usage stats

# Vision statement

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
* GitHub
* https://github.com/austinglaser/csci3308-project

# Requirements

# Methodology

# Project Tracking software
* Trello

# Project plan

