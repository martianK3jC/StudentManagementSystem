#!/bin/bash

# Update the local development branch
git checkout development
git pull origin development

# Manually define the list of feature branches
feature_branches=("feature/branch1" "feature/branch2" "feature/branch3")

for branch in "${feature_branches[@]}"; do
    # Checkout the feature branch
    git checkout "$branch"

    # Merge the development branch into the feature branch
    git merge development

    # Resolve any conflicts here manually if they occur

    # Push the updated feature branch back to the remote repository
    git push origin "$branch"
done

# Switch back to the development branch
git checkout development
