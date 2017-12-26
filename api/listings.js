import fetch from 'isomorphic-unfetch';

// TODO: Clean up error handling
export const fetchListings = async ctx => {
  let resp, json;
  try {
    resp = await fetch(
      `https://openapi.etsy.com/v2/shops/EvergreenRoots/listings/active?api_key=${
        process.env.ETSY_API_KEY
      }`
    );
  } catch (err) {
    ctx.status = err.status || 500;
    ctx.body = err.message;
    ctx.app.emit('error', err, ctx);
    return;
  }

  if (resp.ok) {
    try {
      json = await resp.json();
    } catch (err) {
      ctx.status = err.status || 500;
      ctx.body = err.message;
      ctx.app.emit('error', err, ctx);
      return;
    }
  } else {
    ctx.status = 500;
    ctx.body = 'Failure';
    ctx.app.emit('error', {}, ctx);
    return;
  }

  ctx.body = json;
};
