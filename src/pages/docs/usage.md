# Usage

## Data

Data is stored in `sbjs.get` object. Here is a list of what you can get:

### `sbjs.get.current`

Params of the latest visitor’s source. If a visitor had more than one source, this will be the latest.

* `sbjs.get.current.typ`
Traffic type. Possible values: `utm`, `organic`, `referral`, `typein`.

* `sbjs.get.current.src`
Source. `utm_source`, actually.

* `sbjs.get.current.mdm`
Medium, `utm_medium`. Values can be customized via utm-params and `referrals`.

* `sbjs.get.current.cmp`
Campaign. Value of `utm_campaign`.

* `sbjs.get.current.cnt`
Content. Value of `utm_content`.

* `sbjs.get.current.trm`
Keyword. Value of `utm_term`.

### `sbjs.get.current_add`

Additional info about a visit.

* `sbjs.get.current_add.fd`
Date and time of a visit. Format: `yyyy-mm-dd hh:mm:ss`. Time zone can be customized via `timezone_offset`.

* `sbjs.get.current_add.ep`
Entrance point.

* `sbjs.get.current_add.rf`
Referer URL.

### `sbjs.get.first` & `sbjs.get.first_add`

Just like `sbjs.get.current` & `sbjs.get.current_add`, but holds data of the very first visit. Stored once, never overwritten.

### `sbjs.get.session`

Current opened session data.

* `sbjs.get.session.pgs`
How many pages user have seen during the current session.

* `sbjs.get.session.cpg`
Current page URL.

### `sbjs.get.udata`

Additional user data: `visits`, `ip` & `user-agent`.

* `sbjs.get.udata.vst`
How many times user visited site.

* `sbjs.get.udata.uip`
Current ip-address.

* `sbjs.get.udata.uag`
Current user-agent (browser).

### `sbjs.get.promo`

Visitor's promocode. This cookie is set only if promocode param is present.

* `sbjs.get.promo.code` Promocode.

## Cookies

All data are stored in cookies.

* `sbjs_current`
* `sbjs_current_add`
* `sbjs_first`
* `sbjs_first_add`
* `sbjs_session`
* `sbjs_udata`
* `sbjs_promo`

### `sbjs_current` & `sbjs_first`

Format:

```bash
typ=organic|||src=google|||mdm=organic|||cmp=(none)|||cnt=(none)|||trm=(none)
```

Examples:

```bash
# source: adv campaign with utms
typ=utm|||src=yandex|||mdm=cpc|||cmp=my_adv_campaign|||cnt=banner_1|||trm=buy_my_stuff

# source: google's SERP
typ=organic|||src=google|||mdm=organic|||cmp=(none)|||cnt=(none)|||trm=(none)

# source: referral from site.com/referer-path
typ=referral|||src=site.com|||mdm=referral|||cmp=(none)|||cnt=/referer-path|||trm=(none)

# source: facebook with custom `referrals` setting
typ=referral|||src=facebook.com|||mdm=social|||cmp=(none)|||cnt=(none)|||trm=(none)

# source: direct visit
typ=typein|||src=(direct)|||mdm=(none)|||cmp=(none)|||cnt=(none)|||trm=(none)
```

### `sbjs_current_add` & `sbjs_first_add`

Format:

```bash
fd=2014-06-11 17:28:26|||ep=http://statica.alexfedoseev.com/sourcebuster-js/|||rf=https://www.google.com
```

### `sbjs_session`

Format:

```bash
pgs=3|||cpg=http://statica.alexfedoseev.com/sourcebuster-js/
```

### `sbjs_udata`

Format:

```bash
vst=2|||uip=192.168.1.1|uag=Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/35.0.1916.114 Safari/537.36
```

### `sbjs_promo`

Format:

```bash
code=002354
```

### Limitations

**Visits from https to http**
When a visitor come from `https` web-site to `http`, a request doesn't have a referer. So `sourcebuster` will consider it as `typein` (direct visit).
