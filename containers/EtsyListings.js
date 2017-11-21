import PropTypes from 'prop-types';
import { fetchListings } from '../utils/endpoints';
import { Component } from 'react';

class EtsyListings extends Component {
  constructor(props) {
    super(props);
    this.state = {
      error: '',
      isFetching: false,
      items: [],
    };
  }

  componentDidMount() {
    fetchListings()
      .then(
        res => res.json(),
        () => this.setState({ error: 'Error loading Etsy listings.' })
      )
      .then(
        ({ results }) => this.setState({ items: results }),
        () => this.setState({ error: 'Error parsing Etsy listings.' })
      );
  }

  render() {
    return this.props.children({
      error: this.state.error,
      isFetching: this.state.isFetching,
      items: this.state.items,
    });
  }
}

EtsyListings.propTypes = {
  children: PropTypes.func,
};

export default EtsyListings;
