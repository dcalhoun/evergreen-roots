const fetch = require('isomorphic-unfetch');

exports.fetchListings = async ctx => {
  const resp = await fetch(
    `https://openapi.etsy.com/v2/shops/EvergreenRoots/listings/active?api_key=${
      process.env.ETSY_API_KEY
    }`
  );
  const json = await resp.json();
  ctx.body = json;
};
