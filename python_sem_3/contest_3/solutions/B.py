import rstr


# ÐÐ¾Ð¶Ð°Ð»ÑÐ¹ÑÑÐ°, ÑÑÐ°Ð±Ð¾ÑÐ°Ð¹, Ñ ÑÐµÐ±Ñ ÑÐ¼Ð¾Ð»ÑÑ

# ÐÐ° ÑÐµÐ´ÑÐ¼Ð¾Ð¼ ÑÑÐ°Ð¶Ðµ Ð·Ð° ÑÐµÐ¼Ñ ÑÐ°ÑÐ¾Ð² ÑÑÐ°ÑÑÑÑ
# Ð¡Ð¿Ð°ÑÐ¸Ð±Ð¾ ÑÐµÐ±Ðµ, Ð¸ Ð·Ð½Ð°ÐµÑÑ ÑÐµÐ¿ÐµÑÑ
# Ð£Ð²Ð¸Ð´ÐµÑÑ Ð±Ñ Ð²Ð½Ð¾Ð²Ñ ÑÐµÐ±Ñ Ñ Ð²ÑÐ¾Ð´Ðµ
# ÐÐ½Ð°Ñ, ÑÑÐ¾ ÑÐ°ÐºÐ¾Ðµ Ð»ÑÐ±Ð¾Ð²Ñ

# ÐÐ¾Ð·Ð¾Ð²Ð¸ Ð¼ÐµÐ½Ñ Ñ ÑÐ¾Ð±Ð¾Ð¹
# Ð¯ Ð¿ÑÐ¸Ð´Ñ ÑÐºÐ²Ð¾Ð·Ñ Ð·Ð»ÑÐµ Ð½Ð¾ÑÐ¸
# Ð¯ Ð¾ÑÐ¿ÑÐ°Ð²Ð»ÑÑÑ Ð·Ð° ÑÐ¾Ð±Ð¾Ð¹
# Ð§ÑÐ¾ Ð±Ñ Ð¿ÑÑÑ Ð¼Ð½Ðµ Ð½Ð¸ Ð¿ÑÐ¾ÑÐ¾ÑÐ¸Ð»
# Ð¯ Ð¿ÑÐ¸Ð´Ñ ÑÑÐ´Ð°, Ð³Ð´Ðµ ÑÑ
# ÐÐ°ÑÐ¸ÑÑÐµÑÑ Ð² Ð½ÐµÐ±Ðµ ÑÐ¾Ð»Ð½ÑÐµ
# ÐÐ´Ðµ ÑÐ°Ð·Ð±Ð¸ÑÑÐµ Ð¼ÐµÑÑÑ
# ÐÐ±ÑÐµÑÐ°ÑÑ ÑÐ½Ð¾Ð²Ð° ÑÐ¸Ð»Ñ Ð²ÑÑÐ¾ÑÑ

def email_generator(regex: str = None,
                    local_mask: str = None,
                    domain_mask: str = None,
                    size: int = None):
    default_local = r"[a-z0-9]+(?:\.[a-z0-9]+)*"
    default_domain = r"(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z]{2,}"
    l_mask = local_mask if local_mask else default_local
    d_mask = domain_mask if domain_mask else default_domain
    if regex is None:
        full_regex = f"{l_mask}@{d_mask}"
    else:
        if local_mask:
            l_mask = f"({regex.split('@')[0]})|({l_mask})"
        if domain_mask:
            d_mask = f"({regex.split('@')[1]})|({d_mask})"
        full_regex = f"{l_mask}@{d_mask}"
    used = set()
    while size is None or size > 0:
        s = rstr.xeger(full_regex)
        counter = 0
        while s in used:
            if counter > 3 * len(used):
                break
            s = rstr.xeger(full_regex)
            counter += 1
        used.add(s)
        yield s
        if size is not None:
            size -= 1
