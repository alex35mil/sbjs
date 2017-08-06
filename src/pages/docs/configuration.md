# Configuration

You can configure `sourcebuster` by passing optional object with params. Usually, it looks like this:

```js
sbjs.init({
  domain: 'site.com',
  lifetime: 3,
  callback: doSomething,
});
```

## Params

* `lifetime`
* `session_length`
* `domain`
* `referrals`
* `organics`
* `typein_attributes`
* `timezone_offset`
* `campaign_param`
* `user_ip`
* `promocode`
* `callback`

### `lifetime`

```js
lifetime: 6 // months
```

Custom expiration period of `sourcebuster` cookies (in months). Default is 6.

### `session_length`

```js
session_length: 30 // minutes
```

User’s session duration (in minutes). Default is 30.

This parameter affects only referral sources overriding. When a visitor comes on your site for the first time, `sourcebuster` receives and stores data about a source. After some time, this visitor might return to your website, but from another source, and we need some rules to decide if we should overwrite previous source or not.

These rules are aligned with Google Analytics:

* UTM and Organic sources always override any previous source.
* Type-in never overrides a previous source.
* Referral source overrides previous source only if there is no user session at the moment. If it’s within the same session — a referral source will never override previous source.

_Explanation to referral logic: sometimes visitor within a current visit (session) comes to a website from a “source” which is not actually a “source”. For example, it can be visit from an email service, where he had a registration activation link._

### `domain`

```js
domain: {
  host: 'site.com',
  isolate: false,
}
```

Cookies domain.

First of all, let's talk about how script handles an absence of this custom option: if no value is set, cookies will be placed for **current domain and all its subdomains**.

Why it acts like this? Lets say a site doesn't have subdomains to share traffic with, and now it doesn't matter: do we share cookies with subdomains or we do not. But what's gonna happen if someday subdomains will occur? If cookies wasn't shared — subdomains won't get them, it means they won't share a traffic, and visitors, which came from main domain to subdomains (and vice versa), will be considered as referral traffic.

So, by default cookies are shared. However, if you don't want to share them — use `isolate: true` param, to isolate domain.

Let’s take a look at further examples.

**Scenario #1**
There's a site: `foo.com`. Also, there's a blog on this site: `blog.foo.com`. And you don’t want to split traffic between them. It means that when a visitor comes from `blog.foo.com` to `foo.com`, it won’t be considered as a new visit for `foo.com` (with `blog.foo.com` as `referral` source), it will be a common inner click without source change (to `sourcebuster` this scenario will be equal to inner page change: e.g. from `foo.com/about` to `foo.com/contacts`). To achieve this, you have to add this line on both sites: `foo.com` & `blog.foo.com`.

```js
domain: 'foo.com'
```

**Scenario #2**
That was simple. Now, let's take a look at opposite scenario — you want to split traffic between your subdomains and consider it as `referral`. There is a main site — `foo.com`, and there is a blog on this site — `blog.foo.com`, which also has users subdomains — `alex.blog.foo.com` is one of them. You don’t want to split traffic between `blog.foo.com` and `alex.blog.foo.com`, but you do want to split it between all blogs and the main site. Here’s how we can sort it out:

```js
// put this on the main domain foo.com
domain: {
  host: 'foo.com',
  isolate: true
}

// and this on the blogs subdomains (blog.foo.com & alex.blog.foo.com)
domain: 'blog.foo.com'
```

Pay attention to the `isolate: true` param in the config for the main domain. Use it only when all incoming traffic from all subdomains should be considered as a referral in relation to provided `host`.

In our example, if a visitor comes for the first time on the main site `foo.com` by clicking on a link in user’s blog `alex.blog.foo.com`, his source (for the `foo.com`) will be `alex.blog.foo.com` (traffic type: `referral`).

**NB! Do not change `isolate` value after you pushed configuration to production! If you'll do — your visitors will get doubled cookies and bad things may happen.**

Check yourself that `isolate` is set right:

Host of a page, which code contains param `domain` with `isolate: true` must be equal to a `host` provided in `domain`:

```js
// CORRECT: on pages of foo.com
domain: {
  host: 'foo.com',
  isolate: true
}

// DOESN’T MAKE SENSE: on pages blog.foo.com
domain: {
  host: 'foo.com',
  isolate: true
}
```

All incoming traffic from all subdomains will be referral in relation to provided host:

```js
domain: {
  host: 'foo.com',
  isolate: true
}
// visit from any subdomain (*.foo.com) → foo.com will be referral
```

### `referrals`

```js
referrals: [
  {
    host: 't.co',            // This is host from Twitter's http referer
    medium: 'social',        // This is custom `utm_medium`, you can drop it and it'll be `referral`
    display: 'twitter.com'   // And this is how you'll see it in the result data
  },
  {
    host: 'plus.url.google.com',
    display: 'plus.google.com'
  }
]
```

Add custom referral sources.

In general, if you’re ok with a fact that `medium` (`utm_medium`) of traffic from `facebook.com` is `referral`, you don’t need this param. But if you want to make this kind of traffic `social` (`utm_medium=social`), you can set it up using `referrals`. First param is host of the source from http referer, second — medium — preferred value of `utm_medium`.

Moreover, some of traffic sources have different referer host in relation to their main domain (e.g. traffic from Twitter has referer with the host — `t.co`). In such case you can assign alias to a source using optional `display` param. Also, with this param you can group a traffic from the set of the sites into one virtual source.

**Twitter** (`host: 't.co', display: 'twitter.com'`) and **Google+** (`host: 'plus.url.google.com', display: 'plus.google.com'`) are already added to default referral sources. You still can override it by your custom setting (for example, to consider it as a social).

### `organics`

There are a number of predefined organic sources are added in the core:

```bash
Source         ->  Alias
-------------------------
google.all     ->  google
yandex.all     ->  yandex
bing.com       ->  bing
yahoo.com      ->  yahoo
about.com      ->  about
aol.com        ->  aol
ask.com        ->  ask
globososo.com  ->  globo
go.mail.ru     ->  go.mail.ru
rambler.ru     ->  rambler
tut.by         ->  tut.by
```

But you can use this param if you want to add more organic sources or override aliases of predefined ones.

```js
organics: [
  {
    host: 'bing.com',
    param: 'q',
    display: 'bing_in_da_house'
  }
]
```

For example, you want a traffic from SERP of `bing.com` to be `organic` and an alias for this source to be `bing_in_da_house`. So you need to provide `host: 'bing.com'`, and a `query` param of keyword — `'q'`. Both are required. Also, to set custom alias for this source, provide optional third param `display: 'bing_in_da_house'`.

To get a keyword `param` go to `bing.com` and search for something, i.e. `“apple”`. After you’ll get to SERP, explore its URL:

```bash
http://www.bing.com/search?q=apple&go=&qs=n&form=QBLH&pq=apple&sc=8-5&sp=-1&sk=&cvid=718ad07527244c319ecebf44aa261f64
```

Keyword param — `'q'` — is a symbol/word between `“?”` (or `“&”` if a param is not the first after question sign) and `“=apple”` in SERP's URL.

### `typein_attributes`

```js
typein_attributes: {
  source: '(direct)',
  medium: '(none)',
}
```

Custom `utm_source` and `utm_medium` for type-in traffic. By default, values of source and medium for type-in traffic are `(direct)` & `(none)`. You can override this via `typein_attributes`.

### `timezone_offset`

```js
timezone_offset: 3
```

By default, datetime is taken from a visitor's system. But you can normalize it to predefined time zone via `timezone_offset` param.

Example. Your visitor is in **London (UTC +00:00)**. His local time is **03:00 AM**. If no `timezone_offset` is set, a time in cookie will be **03:00 AM**. Another visitor at the same moment is from **Berlin (UTC +01:00)** and his local time is **04:00 AM**. The time in cookie will be **04:00 AM**.

If you want to normalize time of all visitors (let it be **UTC +03:00**), you should set it via `timezone_offset: 3`. So a time in cookies of both visitors will be **06:00 AM**.

### `campaign_param` (Google AdWords `gclid` param handler)

```js
campaign_param: 'my_adwords_campaign'
```

Custom GET-param, whose value (if present) will be set as `utm_campaign` in cookies (if there is no original `utm_campaign` in request). This feature was added mainly because of Google AdWords `gclid` param.

Here is a use-case. If traffic is from Google AdWords and you use `gclid` param, you can shorten your urls by removing `utm` noise. Sourcebuster will match this traffic as `utm` from Google.

If there is only `gclid` param in url, e.g. `http://foo.com/?gclid=googlesHash`

This will give you the following results:

* Traffic type: `utm`
* utm_source: `google`
* utm_medium: `cpc`
* utm_campaign: `google_cpc`
* utm_content: `(none)`
* utm_term: `(none)`

You can provide a custom `utm_campaign` name via `campaign_param` and value of this GET-param: `http://foo.com/?gclid=googlesHash&my_adwords_campaign=custom_campaign`

You'll get the following:

* Traffic type: `utm`
* utm_source: `google`
* utm_medium: `cpc`
* utm_campaign: `custom_campaign`
* utm_content: `(none)`
* utm_term: `(none)`

**WARNING**
* If there is original utm-param in request (`utm_source`, `utm_medium`, `utm_campaign`), it will override `gclid` param and `campaign_param` param value.
* If there is only custom campaign param (`campaign_param`) in request, `sourcebuster` will consider it as `utm` traffic.

### `user_ip`

```js
user_ip: '192.168.1.1'
```

User’s ip address. By default, `sourcebuster` can’t get ip address of a visitor. But if you need it, you can get it on your backend and push it using `user_ip` param.

### `promocode`

```js
promocode: true

// or
promocode: {
  min: 100000,
  max: 999999,
}
```

Generate (pseudo) random promocodes for visitors.

If you don't want to bother yourself with promocode stuff on your backend, `sourcebuster` can generate them for you. There is no check for uniqueness, of course. But you can rely on probability and set range of promocode values via `min` and `max` params. They are optional, by the way. If they are not set, range will be between `100 000` and `999 999`.

### `callback`

```js
callback: doSomething
```

Callback. Just pass a function to this option, and it will be executed right after cookies are set. Callback will get an object with `sbjs` data as argument.

```js
function logSource(sbData) {
  console.log(`Cookies are set! Your source is: ${sbData.current.src}`);
}

sbjs.init({ callback: logSource });
```
