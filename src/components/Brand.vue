

<template>
  <div id="brand" class="pos-fix flex-col flex-center slide-down-in">
    <div class="body flex-col flex-center slide-down-in">
      <RouterLink to="/" rel="start">
        <p class="author">{{ author }}</p>
        <h1>{{ CNName }}</h1>
      </RouterLink>
      <p class="description flex-row">{{ description }}</p>
    </div>
  </div>
</template>
<script setup>
import { RouterLink } from "vue-router";
import config from "../../public/config";
const { author, CNName, description } = config;
</script>

<style lang='scss' scoped>
#brand {
  padding: 3rem 5rem 0;
  text-align: center;
  width: 100%;
  height: 50vh;
  min-height: 10rem;
  z-index: 997;
  .body {
    a:hover {
      color: currentColor;
    }
    .author {
      font-family: "Fredericka the Great", Mulish, -apple-system, "PingFang SC",
        "Microsoft YaHei", sans-serif;
      font-size: 3.5em;
      line-height: 1.2;
    }
    h1 {
      font-size: 2.5em;
      letter-spacing: 0.125rem;
    }
    .author + h1 {
      margin: 0.625rem 0;
    }
  }
  .description {
    font-size: 0.875em;
    margin: 0;
  }
  @media (min-width: 768px) and (max-width: 991px) {
    .description {
      font-size: 0.8125em;
    }
  }
}

@media (max-width: 767px) {
  #brand {
    padding: 3rem 0.5rem 0;
  }

  #brand h1 {
    font-size: 1.5em;
  }

  #brand .description {
    font-size: 0.75em;
  }
}

@media (max-width: 413px) {
  #brand .author {
    font-size: 2.5em;
  }
}
</style>