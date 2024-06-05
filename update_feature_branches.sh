#!/bin/bash

#* Update the local development branch
git checkout development
git fetch
git pull origin development

#* Manually define the list of feature branches
feature_branches=(
    "add-student"
    "delete-student"
    "designs-branch"
    "file-handling"
    "management-menu"
    "search-student"
    "struct-student"
    "update-student"
    "view-students"
    "user-interface"
)

for branch in "${feature_branches[@]}"; do
    git checkout "$branch"
    
    git merge development

    #* Resolve any conflicts here manually if they occur
    
    git push origin "$branch"
done

#* Switch back to the development branch
git checkout development
