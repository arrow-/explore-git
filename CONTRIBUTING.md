#CONTRIBUTING

Fork this repo, make changes, test code, submit pr.
***
***Comment on the issue to let everyone know you are working on it. Why should 14 people develop just 1 feature which can be developed by a far less number of people and there are numerous other things to work on?
Be responsible.***
***
The aim of the event is to **Teach Git Hands-On**. Due to time constraints, the projects we provide for hacking ***cannot***

- be difficult, the aim is to learn `git` and not computer science.
- require too much implentation or testing time.
- require special installation or setup.
- have complete implentations.
- have sloppy code, documentation or organisation.

but, ***they must have***

- A clear set of minimum functionalities.
> This could be a set of functions which have been declared but not defined. Team assigned to `functionality A0` is responsible for it.

- Presentable as professional code, modularised (split into multiple files, each file not more than 250 lines), well abstracted.
> Most participants will never have read awesome production source code, and it is very important that they see well crafted code. The projects should set a high standard.

#Event Flow

*Hey! edit this, as much as you like.*

##1 hour
Teaching `git` using a dummy repository, everyone works individually.
Use [dont-be-afraid-to-commit](http://dont-be-afraid-to-commit.readthedocs.org/) or the [github tutorial](https://try.github.io/levels/1/challenges/1).

##1:45 hour
Participants form groups of size 2-3. Each team selects a project based on their language preference, and project availability.
Multiple teams will fork a project to add functionality, fix bugs and review code submitted by others. *Organisers will manage the PRs, enforcing style, and correctness*.

For everyone's sake, The teams working on the same project will assign the work to themselves through the repo-owners (us), so that no two groups work on the same thing *(to save effort, time and not just because we want to avoid `merge conflicts`)*
Hence, the project must have a minimum set of `definite goals`, which can be assigned to teams. Further goals can be added if time permits. All of this can be managed very easily through GitHub milestones, version tags and assignees.

#Requirements from a Project

Please add only those scripts which will be provided to participants for *collaborative hacking* **to learn `git`**.
Add a `.md` to explain the Aim, and list-of-needs, to make the development process clear. Remember we have only 90 minutes.
Think about these before selecting/building a project:

* If 5 people make changes to it, will they be adding different functionality?
>they should be. why waste developer effort and time?

* Will this project have all the development phases: `fork/clone` then `develop - submit_pr - review - merge` cycle and `issue`?
Or will it be `fork/clone` then `modify` and `forget-original`?
>We need all phases. *I know most of the cool scripts fall in the `forget-original` category* :sob:

* Will the PRs have a lot of overlap with one another?
>they should not. Teams working on the same project should review code submitted by others too. Make an issue, if required.

* Most importantly, will participants be able to understand the code and be confident enough to write new code **knowing that their code is going to reviewd by the crowd?**
>If the code to be added is trivial, no one will hesitate.

* Do participants have a good incentive to write the code? To write **good** code?
>We could select good contributions and congratulate them after the event. *I have Anokha coupons...* :stuck_out_tongue_winking_eye:
* *Anything Else?*