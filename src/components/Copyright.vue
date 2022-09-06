<template>
  <div class="status">
    <div class="copyright">
      © 2010 – <span itemprop="copyrightYear">{{ currentYear }}</span>
      <span class="with-love"><i class="ic i-sakura rotate"></i> </span
      ><span class="author" itemprop="copyrightHolder">{{ author }}</span>
    </div>

    <div class="powered-by">
      基于
      <a
        href="https://hexo.io"
        rel="noopener external nofollow noreferrer"
        target="_blank"
        class="exturl"
        title="Hexo"
        >Hexo</a
      >
      &amp; Theme.<a
        href="https://github.com/amehime/hexo-theme-shoka"
        rel="noopener external nofollow noreferrer"
        target="_blank"
        class="exturl font-pink"
        title="Shoka"
        >Shoka</a
      >
    </div>
  </div>
</template>
<script setup>
import config from "../../public/config";
const { author } = config;
const currentDate = new Date();
const currentYear = currentDate.getFullYear();
</script>
<style lang="scss" scoped>
.font-pink {
  color: #ffc0cb;
}
</style>