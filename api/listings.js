import fetch from 'isomorphic-unfetch';

const emitError = (ctx, err) => {
  ctx.status = err.status || 500;
  ctx.body = err.message;
  ctx.app.emit('error', err, ctx);
};

export const fetchListings = async ctx => {
  let resp, json;
  try {
    resp = await fetch(
      `https://openapi.etsy.com/v2/shops/EvergreenRoots/listings/active?api_key=${
        process.env.ETSY_API_KEY
      }`
    );
  } catch (err) {
    emitError(ctx, err);
    return;
  }

  if (resp.ok) {
    try {
      json = await resp.json();
    } catch (err) {
      emitError(ctx, err);
      return;
    }
  } else {
    emitError(ctx, { status: resp.status, message: 'Network failure.' });
    return;
  }

  ctx.body = json;
};
