const fetch = require('isomorphic-unfetch');

// TODO: Move secret key to environment variable
const ETSY_API_KEY = '';

exports.fetchListings = async ctx => {
  const resp = await fetch(
    `https://openapi.etsy.com/v2/shops/EvergreenRoots/listings/active?api_key=${
      ETSY_API_KEY
    }`
  );
  const json = await resp.json();
  ctx.body = json;
};
