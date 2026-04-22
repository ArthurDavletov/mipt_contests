import sys

logins = set()

for login in sys.stdin:
    local_name, domain = login.rstrip("\n").split("@")
    local_name = local_name.replace(".", "")
    if "+" in local_name:
        local_name = local_name[:local_name.index("+")]
    logins.add(local_name + domain)

print(len(logins))
