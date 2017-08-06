# Installation

Get it via `yarn` or `npm`:

```bash
yarn add sourcebuster
npm install --save sourcebuster
```

And import in your code:

```js
// CommonJS
const sbjs = require('sourcebuster');

// ES6
import sbjs from 'sourcebuster';
```

Then initialize it:

```js
sbjs.init();
```

## Old school

[Download github repo](https://github.com/alexfedoseev/sourcebuster-js/archive/master.zip). You need `sourcebuster.min.js` file form `/dist` folder.

You can inject it in your html like this:

```html
<!-- Make available on a page -->
<script src="/path/to/sourcebuster.min.js"></script>

<!-- Initialize -->
<script>
  sbjs.init();
</script>
```
